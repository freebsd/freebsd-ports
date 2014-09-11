# $FreeBSD$

PORTNAME=	gentoo-stage3
PORTVERSION=	20140812
CATEGORIES=	emulators linux
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	releases/x86/autobuilds/current-stage3$-{GENTOO_OPTIMIZED}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Files from Gentoo distribution, for Linux compatibility

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi

RESTRICTED=	binaries licensed under GNU GPL without accompanying source
BROKEN=		Fails to package

USES=		tar:bzip2
DIST_SUBDIR=		gentoo-linux
NO_BUILD=		YES
ONLY_FOR_ARCHS=		i386 amd64
GENTOO_OPTIMIZED?=	i486
SUB_FILES+=		pkg-message pkg-install pkg-deinstall
SUB_LIST+=		PREFIX_SUBDIR="${PREFIX_SUBDIR}" STAGEDIR="${STAGEDIR}"
PLIST_SUB+=		PREFIX_SUBDIR="${PREFIX_SUBDIR}"
PLIST=			${PKGDIR}/pkg-plist.${GENTOO_OPTIMIZED}
PKGMESSAGE=		${WRKDIR}/pkg-message
PKGINSTALL=		${WRKDIR}/pkg-install
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall

.if defined(WITH_LINUXBASE)
PKGNAMEPREFIX=	linux_base-
CONFLICTS=	linux_base-7* linux_base-8* linux_base-debian* \
		linux_base-rh* linux_base-suse* linux_base-f* \
		linux_base-gentoo-stage[12]-* linux_base-c*
USE_LINUX_PREFIX=	YES
PREFIX_SUBDIR=
.else
NO_MTREE=	YES
PKGNAMEPREFIX=	linux_dist-
PREFIX_SUBDIR=	${PORTNAME}/
.endif

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING) || (defined(PACKAGE_BUILDING) && !defined(LINUX_OSRELEASE) )
LINUX_OSRELEASE!=	${ECHO_CMD} `${SYSCTL} -n compat.linux.osrelease 2>/dev/null`
.endif

.if ${LINUX_OSRELEASE}x == "x"
IGNORE=			linuxulator is not (kld)loaded
.endif

.if (${GENTOO_OPTIMIZED} == "i686")
MASTER_SITE_SUBDIR=	releases/x86/autobuilds/${PORTVERSION}
DISTNAME=	stage3-${GENTOO_OPTIMIZED}-${PORTVERSION}
.else
MASTER_SITE_SUBDIR=	releases/x86/autobuilds/${PORTVERSION}
DISTNAME=	stage3-i486-${PORTVERSION}
.endif

do-extract:
	${MKDIR} ${WRKDIR}

pre-fetch:
.if defined(WITH_LINUXBASE)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Note that this port doesn't completely suit our ports"
	@${ECHO_MSG} "infrastructure.  It's very good for a standalone Linux"
	@${ECHO_MSG} "distribution on a FreeBSD system you can use for"
	@${ECHO_MSG} "cross-developing and cross-building, etc., but using it as a"
	@${ECHO_MSG} "linux_base port is not quite adequate."
	@${ECHO_MSG} "If you experience troubles with it, please use the"
	@${ECHO_MSG} "default linux_base port."
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This port is a complete Linux distribution you can use"
	@${ECHO_MSG} "on a FreeBSD system.  The use of this port as a linux_base"
	@${ECHO_MSG} "port is very discouraged but you can enforce it to install"
	@${ECHO_MSG} "as a linux_base if you set WITH_LINUXBASE."
	@${ECHO_MSG} ""
.endif
	@${ECHO_MSG} "You can select your processor class for installing optimized"
	@${ECHO_MSG} "Gentoo binaries with setting this knob"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "GENTOO_OPTIMIZED=[i486|i686]."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The default is i486."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "                         WARNING"
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "The i686 version may segfault in some environments."
	@${ECHO_MSG} "If this is your case, please use the i486 version."
	@${ECHO_MSG} ""

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PREFIX_SUBDIR}
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${TAR} --exclude=./dev -xpy --exclude=./proc --exclude=./lib/udev \
		--exclude=./lib/udev-state \
		 -C ${STAGEDIR}${PREFIX}/${PREFIX_SUBDIR} \
		-f ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@${CP} -p /etc/resolv.conf ${STAGEDIR}${PREFIX}/${PREFIX_SUBDIR}/etc/
	@${FIND} ${STAGEDIR}${PREFIX}/${PREFIX_SUBDIR}bin ${STAGEDIR}${PREFIX}/${PREFIX_SUBDIR}sbin/ \
		${STAGEDIR}${PREFIX}/${PREFIX_SUBDIR}usr/bin ${STAGEDIR}${PREFIX}/${PREFIX_SUBDIR}/usr/sbin \
		-type f -print0 | ${XARGS} -0 ${FILE} \
		| ${GREP} ELF | ${CUT} -d : -f 1 | ${XARGS} ${BRANDELF} -t Linux
	@${BRANDELF} -t Linux ${STAGEDIR}${PREFIX}/${PREFIX_SUBDIR}/lib/ld-*.so
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

plist:
	${TOUCH} pkg-plist.new
	${FIND} ${PREFIX}/${PREFIX_SUBDIR} -type f -o -type l | ${SORT} | \
		${SED} 's|${PREFIX}/${PREFIX_SUBDIR}|%%PREFIX_SUBDIR%%|g' >>pkg-plist.new
	${FIND} ${PREFIX}/${PREFIX_SUBDIR} -type d | ${SORT} -r | \
		${SED} 's|${PREFIX}/${PREFIX_SUBDIR}|@dirrm %%PREFIX_SUBDIR%%|g' | \
		${GREP} -v '^${PREFIX}/${PREFIX_SUBDIR}$$' >>pkg-plist.new
	${ECHO_CMD} "@dirrmtry %%PREFIX_SUBDIR%%" >>pkg-plist.new

update-port:
	${MAKE} distclean
	${MAKE} distclean GENTOO_OPTIMIZED=i686
	-${RM} ${DISTINFO_FILE}
	${MAKE} makesum
	${MV} ${DISTINFO_FILE} ${DISTINFO_FILE}.new
	${MAKE} makesum GENTOO_OPTIMIZED=i686
	${CAT} ${DISTINFO_FILE} >> ${DISTINFO_FILE}.new
	${MV} ${DISTINFO_FILE}.new ${DISTINFO_FILE}
	${MAKE} deinstall
	${RM} -rf ${PREFIX}/${PREFIX_SUBDIR}
	${MAKE} install
	${MAKE} plist
	${MV} pkg-plist.new pkg-plist.i486
	${MAKE} deinstall
	${RM} -rf ${PREFIX}/${PREFIX_SUBDIR}
	${MAKE} install GENTOO_OPTIMIZED=i686
	${MAKE} plist
	${MV} pkg-plist.new pkg-plist.i686
	${MAKE} deinstall
	${RM} -rf ${PREFIX}/${PREFIX_SUBDIR}
	${MAKE} distclean
	${MAKE} distclean GENTOO_OPTIMIZED=i686

.include <bsd.port.post.mk>
