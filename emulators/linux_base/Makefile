# New ports collection makefile for:    linux_base
# Version required:     5.2
# Date created:         Jul 7, 1999
# Whom:                 marcel@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=		linux_base
PKGNAME=		linux_base-5.2
CATEGORIES=		emulators
MASTER_SITES=		\
	ftp://ftp.cdrom.com/pub/linux/redhat/${STDDIR}/ \
	ftp://ftp.redhat.com/redhat/${STDDIR}/ \
	ftp://ftp.infomagic.com/pub/mirrors/linux/RedHat/${STDDIR}/ \
	ftp://ftp.crc.ca/mirrors/by-site/ftp.redhat.com/redhat/${STDDIR}/ \
	ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/${STDDIR}/ \
	ftp://mirror.nucba.ac.jp/mirror/redhat/${STDDIR}/ \
	ftp://ftp.is.co.za/linux/distributions/redhat/${STDDIR}/ \
	ftp://mirror.aarnet.edu.au/pub/linux/redhat/${STDDIR}/
DISTFILES=		${RPM_SET1} ${RPM_LDCONFIG} ${RPM_SET2} \
			${RPM_RPM} ${RPM_SET3}

MAINTAINER=		marcel@FreeBSD.org

RUN_DEPENDS=		rpm:${PORTSDIR}/misc/rpm

ONLY_FOR_ARCHS=		i386 alpha
DIST_SUBDIR=		rpm
PREFIX=			/compat/linux
EXTRACT_ONLY=
NO_BUILD=		yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
PLIST=			${PKGDIR}/PLIST.${ARCH}

STDDIR=			old-releases/redhat-5.2/${ARCH}/RedHat/RPMS

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
LIBC5_COMPAT=		ld.so-1.9.5-8.i386.rpm \
			libc-5.3.12-27.i386.rpm \
			libg++-2.7.2.8-9.i386.rpm
.else
LIBC5_COMPAT=
.endif

#
# The file files/pkg-list lists all rpms that are installed by this port
# versus all rpms installed by a minimal Redhat installation.
#
RPM_SET1=		setup-1.9.2-1.noarch.rpm \
			filesystem-1.3.2-3.noarch.rpm \
			basesystem-4.9-3.noarch.rpm
RPM_LDCONFIG=		ldconfig-1.9.5-8.${ARCH}.rpm
RPM_SET2=		glibc-2.0.7-29.${ARCH}.rpm \
			termcap-9.12.6-11.noarch.rpm \
			libtermcap-2.0.8-10.${ARCH}.rpm \
			bash-1.14.7-13.${ARCH}.rpm \
			ncurses-4.2-10.${ARCH}.rpm \
			zlib-1.1.3-2.${ARCH}.rpm \
			info-3.12-9.${ARCH}.rpm \
			fileutils-3.16-10.${ARCH}.rpm \
			grep-2.2-2.${ARCH}.rpm \
			binutils-2.9.1.0.15-1.${ARCH}.rpm \
			gd-1.3-3.${ARCH}.rpm \
			gdbm-1.7.3-17.${ARCH}.rpm \
			glib-1.0.6-3.${ARCH}.rpm \
			${LIBC5_COMPAT} \
			libstdc++-2.8.0-14.${ARCH}.rpm \
			sh-utils-1.16-14.${ARCH}.rpm \
			readline-2.2.1-1.${ARCH}.rpm \
			redhat-release-5.2-1.noarch.rpm
RPM_RPM=		rpm-2.5.5-5.2.${ARCH}.rpm
RPM_SET3=		setserial-2.14-4.${ARCH}.rpm \
			slang-0.99.38-8.${ARCH}.rpm \
			stat-1.5-8.${ARCH}.rpm \
			tcsh-6.07.09-1.${ARCH}.rpm \
			XFree86-libs-3.3.2.3-25.${ARCH}.rpm \
			xpm-3.4j-3.${ARCH}.rpm

DBPATH=			/var/lib/rpm
RPMFLAGS=		--ignoreos --root ${PREFIX} --dbpath ${DBPATH} \
			--nodeps --replacepkgs
RPMDIR=			${DISTDIR}/${DIST_SUBDIR}

REMOVE_DIRS=		/dev /home /root /tmp /var/tmp /usr/local /usr/tmp
REMOVE_FILES=		/bin/df /bin/su /etc/exports /etc/group /etc/motd \
			/etc/passwd /etc/printcap /etc/services /etc/protocols

.if ${OSVERSION} <= 320001
#
# Hack to let the rpm installer run.  The actual kernel change occurred after
# 400008 on 4.0-current and well after 320001, but we'll assume people running
# -current and -stable stay reasonably up-to-date.
#
# Define this if you get messages that look like
#
# --
# ELF interpreter /compat/linux/lib/ld-linux.so.2 not found
# execution of script failed
# --
#
NEEDLOADLINK=		true
.endif

do-install:
	@if [ -z "`kldstat -v | ${GREP} -E 'linux(aout|elf)'`" ]; then \
		${ECHO} 'Linux mode is not enabled.\
			Loading linux kernel module...' | fmt; \
		linux || { \
		${ECHO} 'The linux kernel module could not be loaded.\
			Please manually load the module and retry.\
			See "man linux" for details.' | fmt; \
		${FALSE}; \
		};\
	fi
	@${MKDIR} ${PREFIX}/${DBPATH}
	@${MKDIR} ${PREFIX}/var/tmp
	@rpm --initdb --root ${PREFIX} --dbpath ${DBPATH}
#
# Make sure we have a /dev/null in the chrooted environment.
#
	@${MKDIR} ${PREFIX}/dev
	@${RM} -f ${PREFIX}/dev/null
	@mknod ${PREFIX}/dev/null c 2 2
	@${CHMOD} 666 ${PREFIX}/dev/null
.if defined(NEEDLOADLINK)
	@${MKDIR} ${PREFIX}/compat
	@${RM} -f ${PREFIX}/compat/linux
	@${LN} -s / ${PREFIX}/compat/linux
.endif
#
# Install all packages. Ignore dependencies just
# like the Red Hat installer.
#
	@for R in ${RPM_SET1}; do \
		${ECHO} $$R; \
		rpm -i ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@${ECHO} ${RPM_LDCONFIG}
	@rpm -i ${RPMFLAGS} --noscripts ${RPMDIR}/${RPM_LDCONFIG}
	@brandelf -t Linux ${PREFIX}/sbin/ldconfig
	@${PREFIX}/sbin/ldconfig
	@${TOUCH} ${PREFIX}/etc/ld.so.conf
	@for R in ${RPM_SET2}; do \
		${ECHO} $$R; \
		rpm -i ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
	@${ECHO} ${RPM_RPM}
	@rpm -i ${RPMFLAGS} --noscripts ${RPMDIR}/${RPM_RPM}
	@brandelf -t Linux ${PREFIX}/bin/rpm
	@for R in ${RPM_SET3}; do \
		${ECHO} $$R; \
		rpm -i ${RPMFLAGS} ${RPMDIR}/$$R; \
	done
#
# Install yp.conf as a hint to NIS users
#
	${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf ${PREFIX}/etc
#
# Finish
#
.if defined(NEEDLOADLINK)
	@${RM} -rf ${PREFIX}/compat
.endif
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${PREFIX}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} ${PREFIX}/$$F; \
	done
	@${LN} -s /var/tmp ${PREFIX}/usr/tmp

post-install:
	@${ECHO} ''
	@fmt ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>
