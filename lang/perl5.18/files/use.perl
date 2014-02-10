#!/bin/sh

# $FreeBSD$

LINK_USRBIN="%%LINK_USRBIN%%"
: ${OSVERSION:=`/sbin/sysctl -n kern.osreldate`};
PERL_ARCH="%%PERL_ARCH%%"
PERL_VERSION="%%PERL_VERSION%%"
PERL_VER="%%PERL_VER%%"
PERL5_SIGNATURE="%%PERL5_SIGNATURE%%"
banner="# added by use.perl $(/bin/date +'%F %T')"
special_link_list="perl perl5"

do_remove_links()
{
	for binary in ${special_link_list} ; do
		if [ -L "/usr/bin/${binary}" ] ; then
			/bin/rm -f "/usr/bin/${binary}"
		fi
	done
	bins=`/bin/ls /usr/bin/*perl*5.* ${PKG_PREFIX}/bin/*perl*5.* 2>/dev/null`
	for binary in ${bins} ; do
		if [ -L "${binary}" ] ; then
			/bin/rm -f "${binary}"
		fi
	done
}

do_create_links()
{
	for binary in ${special_link_list} ; do
		if [ -f "/usr/bin/${binary}" ] ; then
			/bin/mv -f "/usr/bin/${binary}" "/usr/bin/${binary}.freebsd"
		fi
		if [ -e "/usr/bin/${binary}" ] ; then
		elif [ -e "${PKG_PREFIX}/bin/perl${PERL_VERSION}" ] ; then
			/bin/ln -sf "${PKG_PREFIX}/bin/perl${PERL_VERSION}" "/usr/bin/${binary}"
		fi
	done
}

do_post_install()
{
	INCLUDEDIR=/usr/include
	install -d ${PKG_PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/auto
	install -d ${PKG_PREFIX}/lib/perl5/site_perl/${PERL_VER}/auto
	install -d ${PKG_PREFIX}/lib/perl5/${PERL_VER}/man/man3
	cd ${INCLUDEDIR} && ${PKG_PREFIX}/bin/h2ph *.h machine/*.h sys/*.h >/dev/null
}

do_remove_perl5_signature()
{
	[ -f "${PERL5_SIGNATURE}" ] && /bin/rm "${PERL5_SIGNATURE}"
}

do_cleanup_manpath()
{
	if [ -f /etc/manpath.config ] ; then
		/bin/cp -p /etc/manpath.config /etc/manpath.config.new
		/usr/bin/awk 's=0;
			/^#.*use.perl/ { s=1; mode=1 }
			/^#/ { s=1; if (mode != 1) { mode=0 } }
			/^OPTIONAL_MANPATH.*perl5/ { s=1; if (mode == 1) { mode=2 } }
			/^$/ { s=1; if (mode != 2) { mode = 0 } }
			{ if (s != 1) { mode = 0 } if (mode == 0) print }' /etc/manpath.config >/etc/manpath.config.new
		/bin/mv /etc/manpath.config /etc/manpath.config.bak
		/bin/mv /etc/manpath.config.new /etc/manpath.config
	fi
}

do_create_perl5_signature()
{
	echo "${banner}" >>"${PERL5_SIGNATURE}"
	echo "# Do not modify PERL_VERSION here, instead use DEFAULT_VERSIONS= perl5=${PERL_VER}" >>"${PERL5_SIGNATURE}"
	echo "PERL_VERSION=${PERL_VERSION}" >>"${PERL5_SIGNATURE}"
}

do_spam_manpath()
{
	if [ -f /etc/manpath.config ] ; then
		echo "${banner}" >>/etc/manpath.config
		echo "OPTIONAL_MANPATH	${PKG_PREFIX}/lib/perl5/${PERL_VER}/man" >>/etc/manpath.config
		echo "OPTIONAL_MANPATH	${PKG_PREFIX}/lib/perl5/${PERL_VER}/perl/man" >>/etc/manpath.config
	fi
}


if [ "$2" = "POST-INSTALL" ] ; then
	do_remove_perl5_signature
	do_create_perl5_signature
	do_post_install
	if [ ${LINK_USRBIN} = yes ] ; then
		do_remove_links
		do_create_links
	fi
	if [ "${OSVERSION}" -lt 900022 ] ; then
		do_cleanup_manpath
		do_spam_manpath
	fi
elif [ "$2" = "POST-DEINSTALL" ] ; then
	do_remove_perl5_signature
	[ ${LINK_USRBIN} = yes ] && do_remove_links
	[ "${OSVERSION}" -lt 900022 ] && do_cleanup_manpath
fi

exit 0
