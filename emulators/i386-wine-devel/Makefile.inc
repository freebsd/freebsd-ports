# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wine
PORTVERSION=	1.7.30
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/dbn/repos/wine/${DIST_SUBDIR}/${PORTVERSION}
PKGNAMEPREFIX=	i386-
PKGNAMESUFFIX?=	-devel
DISTNAME=	${PKGNAME}
EXTRACT_SUFX=	.txz
DIST_SUBDIR=	freebsd:${OSREL:C/\..*//}:x86:64

MAINTAINER=	dbn@FreeBSD.org
COMMENT?=	32bit Microsoft Windows compatibility environment for 64bit FreeBSD

LICENSE=        LGPL21 LGPL3
LICENSE_COMB=   dual
LICENSE_FILE=   ${WRKDIR}/LICENSE

OPTIONS_DEFINE=	GECKO MONO
GECKO_DESC=     Bundle Gecko MSI package for Wine
MONO_DESC=      Bundle Mono MSI package for Wine

CONFLICTS_INSTALL?=	i386-wine-[0-9]* wine-[0-9]* wine-devel-[0-9]*

EXTRACT_AFTER_ARGS=	-C / --exclude +COMPACT_MANIFEST --exclude +MANIFEST \
				--exclude +MTREE_DIRS --exclude share/licenses/'*' \
				--exclude libdata/ldconfig32/${UNIQUENAME} \
				-s '|/usr/local|${STAGEDIR}${PREFIX}|gs'
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	wine only runs on x86 architecture
SLAVEDIR?=	${.CURDIR}
PKGINSTALL=	${SLAVEDIR}/files/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USE_LDCONFIG32=	${PREFIX}/lib32 ${PREFIX}/lib32/wine
USES=		tar:xz

GECKO_RUN_DEPENDS=	${DATADIR}/gecko/wine_gecko-2.24-x86.msi:${PORTSDIR}/emulators/wine-gecko-devel
MONO_RUN_DEPENDS=	${DATADIR}/mono/wine-mono-4.5.2.msi:${PORTSDIR}/emulators/wine-mono-devel

# Included for OPSYS and OSVERSION
.include <bsd.port.pre.mk>

.for osrel in 8 9 10 11
.if ${OSREL:C/\..*//} == ${osrel}
PLIST_SUB+=	OSREL${osrel}=""
.if ${PKGNAMESUFFIX} == -devel
PLIST_SUB+=	OSREL${osrel}-DEVEL=""
PLIST_SUB+=	OSREL${osrel}-COMPHOLIO="@comment "
.else
PLIST_SUB+=	OSREL${osrel}-DEVEL="@comment "
PLIST_SUB+=	OSREL${osrel}-COMPHOLIO=""
.endif
.else
PLIST_SUB+=	OSREL${osrel}="@comment "
PLIST_SUB+=	OSREL${osrel}-DEVEL="@comment "
PLIST_SUB+=	OSREL${osrel}-COMPHOLIO="@comment "
.endif
.endfor

.if ${OPSYS} != FreeBSD || (!(${OSVERSION} >= 804000 && ${OSVERSION} < 900000) && !(${OSVERSION} >= 901000 && ${OSVERSION} < 1000000) && !(${OSVERSION} >= 1000510 && ${OSVERSION} < 1100000) && !(${OSVERSION} >= 1100040 && ${OSVERSION} < 1200000))
IGNORE=		binaries compiled for FreeBSD 8.4+, 9.1+, 10.0+ and -current only
DISTFILES=
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} -C ${WRKDIR} --include '/usr/local/share/licenses/${PKGNAME}/LICENSE' -s '|/usr/local/share/licenses/${PKGNAME}/||g'

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS}

${PLIST}: fetch
	${TAR} -tf ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS} | ${GREP} -v '/$$' | ${SED} 's|/usr/local/||g' | sort > ${PLIST}

port-update:
	${RM} -f ${SLAVEDIR}/distinfo ${SLAVEDIR}/distinfo~ ${SLAVEDIR}/pkg-plist.*
.for osrel in 8 9 10 11
.for suffix in -devel -compholio
	${MAKE} fetch OSREL=${osrel} PKGNAMESUFFIX=${suffix}
	${MAKE} makesum OSREL=${osrel} PKGNAMESUFFIX=${suffix}
	${CAT} ${SLAVEDIR}/distinfo >> ${SLAVEDIR}/distinfo~
	${RM} ${SLAVEDIR}/distinfo
	${MAKE} pkg-plist.${osrel}${suffix:U} PLIST=pkg-plist.${osrel}${suffix:U} OSREL=${osrel} PKGNAMESUFFIX=${suffix}
.endfor
.endfor
	${MV} ${SLAVEDIR}/distinfo~ ${SLAVEDIR}/distinfo
	python ${FILESDIR}/mergeplist.py ${SLAVEDIR}/pkg-plist.* > ${PLIST}
	${RM} ${SLAVEDIR}/pkg-plist.*

.include <bsd.port.post.mk>
