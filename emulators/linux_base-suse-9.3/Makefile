# New ports collection makefile for:		linux_base-suse-9.3
# Date created:					2005-07-12
# Whom:						trevor
# based on ports/emulators/linux_base by Marcel Moolenaar and others
# and on techniques from mbrolavox port by edwin and pav
#
# $FreeBSD$
#

PORTNAME=		linux_base-suse
PORTVERSION=		9.3
PORTREVISION=		2
CATEGORIES=		emulators linux
MASTER_SITES=		${MASTER_SITE_SUSE} ${MASTER_SITE_SUSE:S/$/:update/}
MASTER_SITE_SUBDIR=	i386/9.3/suse/i586 i386/update/9.3/rpm/i586/:update

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Basic packages for Linux mode from SUSE 9.3/i386

EXTRACT_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

CONFLICTS=	linux_base-7* linux_base-debian* linux_base-gentoo* linux_base-rh* \
		linux_base-suse-9.1* linux_base-suse-9.2*

RPMLIST=	${.CURDIR}/files/rpmlist.conf

.if !defined(OPTIONS)
OPTIONS!=	/usr/bin/awk -F\| '{ print $$1 " \"" $$3 "\" " $$4 }' ${RPMLIST}
.endif
.if !defined(ALLOPTIONS)
ALLOPTIONS!=	/usr/bin/awk -F\| '{ print $$1 }' ${RPMLIST}
.for ii in ${ALLOPTIONS}
FILE_${ii}!=	/usr/bin/grep -w ^${ii} ${RPMLIST} | /usr/bin/awk -F\| '{ print $$2 }'
.endfor
.endif

.include <bsd.port.pre.mk>

# Equivalents to some of the RPMs that may optionally be installed by this port
# may also be installed separately by other ports.
#
# accessibility/linux-atk
.if defined(WITH_atk)
CONFLICTS+=linux-atk-1.2.*
.endif
# audio/linux-arts
.if defined(WITH_arts)
CONFLICTS+=linux-arts-1.0.*
.endif
# audio/linux-libaudiofile
.if defined(WITH_audiofile)
CONFLICTS+=linux-audiofile-0.*
.endif
# devel/linux-glib2
.if defined(WITH_glib2)
CONFLICTS+=linux-glib2-2.2.*
.endif
# devel/linux-libglade
.if defined(WITH_libglade0)
CONFLICTS+=linux-libglade-0.*
.endif
# devel/linux-sdl12
.if defined(WITH_sdl)
CONFLICTS+=linux-sdl12-1.2.*
.endif
# graphics/linux-imlib
.if defined(WITH_imlib)
CONFLICTS+=linux-imlib-1.9.*
.endif
# graphics/linux-jpeg
.if defined(WITH_jpeg)
CONFLICTS+=linux-jpeg-6*
.endif
# graphics/linux-libmng
.if defined(WITH_libmng)
CONFLICTS+=linux-libmng-1.0.*
.endif
# graphics/linux_mesa3
.if defined(WITH_xorgmesa)
CONFLICTS+=linux_mesa3-3.*
.endif
# graphics/linux-png
.if defined(WITH_libpng)
CONFLICTS+=linux-png-1.2.*
.endif
# graphics/linux-tiff
.if defined(WITH_libtiff)
CONFLICTS+=linux-tiff-3.*
.endif
# textproc/linux-expat
.if defined(WITH_expat)
CONFLICTS+=linux-expat-1.*
.endif
# textproc/linux-libxml
.if defined(WITH_libxml1)
CONFLICTS+=linux-xlibxml-1.*
.endif
# x11/linux-XFree86-libs
.if defined(WITH_xorglibs)
CONFLICTS+=linux-XFree86-libs-4.*
.endif
# x11/linux-gnomelibs
.if defined(WITH_gnomelibs)
CONFLICTS+=linux-gnomelibs-1.*
.endif
# x11-fonts/linux-fontconfig
.if defined(WITH_fontconfig)
CONFLICTS+=linux-fontconfig-2.*
.endif
# x11-toolkits/linux-openmotif
.if defined(WITH_openmotif)
CONFLICTS+=linux-openmotif-2.2.*
.endif
# x11-toolkits/linux-gtk
.if defined(WITH_gtk1)
CONFLICTS+=linux-gtk-1.*
.endif
# x11-toolkits/linux-gtk2
.if defined(WITH_gtk2)
CONFLICTS+=linux-gtk2-2.*
.endif
# x11-toolkits/linux-pango
.if defined(WITH_pango)
CONFLICTS+=linux-pango-1.*
.endif

DIST_SUBDIR=		rpm/i386/suse/9.3
IS_INTERACTIVE=	yes
NO_FILTER_SHLIBS=	yes
NO_MTREE=		yes
ONLY_FOR_ARCHS=		amd64 i386
PLIST=			${WRKDIR}/plist
PREFIX=			${LINUXBASE}
RESTRICTED=		"to distribute, must offer sources:  http://www.gnu.org/licenses/gpl.txt"

.for ii in ${ALLOPTIONS}
. if defined(WITH_${ii})
MYDISTFILES+=	${FILE_${ii}}
. endif
.endfor
.if defined(MYDISTFILES)
DISTFILES=	${MYDISTFILES}
DIST_SUBDIR=	rpm/i386/suse/9.3
.else
DISTFILES=	# none
.endif

# Avoid cyclic dependency.
.undef USE_LINUX

REMOVE_DIRS=		boot dev home initrd root tmp var/tmp usr/local usr/tmp
REMOVE_FILES=		bin/df bin/su etc/exports etc/group etc/localtime \
			etc/motd etc/passwd etc/printcap etc/services \
			etc/protocols
BRAND_FILES=		bin/rpm sbin/ldconfig

.if (${ARCH} == "amd64")
LATEST_LINK:=	${LATEST_LINK:C/linux/linux32/}
FALLBACK_ELF_MIB=	kern.elf32.fallback_brand
.else
FALLBACK_ELF_MIB=	kern.fallback_elf_brand
.endif
LINUX_ELF=		3
PREVIOUS_ELF!=		/sbin/sysctl -n ${FALLBACK_ELF_MIB}

distinfo:
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} fetch NO_CHECKSUM=yes \
		DISABLE_SIZE=yes
	@if [ -f ${MD5_FILE} ]; then ${CAT} /dev/null > ${MD5_FILE}; fi
	@(cd ${DISTDIR}; \
	for file in ${_CKSUMFILES}; do \
	${MD5} $$file >> ${MD5_FILE}; \
		if [ -z "${NO_SIZE}" ]; then \
			${ECHO_CMD} "SIZE ($$file) = "`${LS} -ALln $$file | ${AWK} '{print $$5}'` \
				>> ${MD5_FILE}; \
	fi; \
	done)

do-extract:
#
# Handle the loading of the Linux loadable kernel module if required.
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${WRKSRC}/var/lib/rpm ${WRKSRC}/var/tmp ${WRKSRC}/lib
	@cd ${WRKSRC}/lib && ${LN} -sf libtermcap.so.2.0.8 libtermcap.so.2
	LC_ALL=C rpm --initdb --root ${WRKSRC} --dbpath /var/lib/rpm
#
# Set the ELF fallback brand to Linux, so we need not do
# anything special to run statically linked binaries.
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${LINUX_ELF}
#
# Install all packages, ignoring dependencies.
	@for ii in ${MYDISTFILES:S/:update//}; do \
		LC_ALL=C rpm -U --root ${WRKSRC} --dbpath /var/lib/rpm \
			--nodeps --replacepkgs --ignoreos --ignorearch \
			${DISTDIR}/${DIST_SUBDIR}/$$ii; \
	done
	@for F in ${BRAND_FILES}; do \
		${BRANDELF} -t Linux ${WRKSRC}/$$F; \
	done
	@/sbin/sysctl -w ${FALLBACK_ELF_MIB}=${PREVIOUS_ELF}
#
# Install yp.conf as a hint to NIS users and make sure there is an
# mtab in etc, albeit an empty one.  This is needed in a couple of
# cases, notably staroffice6.
#
	${INSTALL} ${COPY} -m 644 ${FILESDIR}/yp.conf ${WRKSRC}/etc
	${TOUCH} ${WRKSRC}/etc/mtab ${WRKSRC}/etc/host.conf
#
# Finish
#
	@for D in ${REMOVE_DIRS}; do \
		${RM} -rf ${WRKSRC}/$$D; \
	done
	@for F in ${REMOVE_FILES}; do \
		${RM} -f ${WRKSRC}/$$F; \
	done
	@${LN} -sf /var/tmp ${WRKSRC}/usr/tmp

do-build:
#
# Generate packing list.
	cd ${WRKSRC} && ${FIND} -s * -type f -o -type l > ${PLIST} \
		&& ${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' >> ${PLIST}

do-install:
#
# Try to hard-link the contents of the work directory to the installation
# directory.  If hard-linking is possible (installing to the same mount point),
# no disk space is consumed in the installation step.  The fallback is to copy,
# and cpio is noisy in this case.
	@cd ${WRKSRC} && ${FIND} * | ${CPIO} -dlmp ${PREFIX}
	@${FIND} ${PREFIX} -type d -exec ${CHMOD} 755 \{\} \;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
