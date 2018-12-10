# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wine
PORTVERSION=	3.20
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/dbn/repos/wine/${DIST_SUBDIR}/
PKGNAMEPREFIX=	i386-
PKGNAMESUFFIX=	-devel
DISTNAME=	${PKGNAME}
EXTRACT_SUFX=	.txz
DIST_SUBDIR=	freebsd:${OSREL:C/\..*//}:x86:64

MAINTAINER=	dbn@FreeBSD.org
COMMENT?=	32-bit Microsoft Windows compatibility environment for 64-bit FreeBSD

LICENSE=        LGPL21 LGPL3
LICENSE_COMB=   dual
LICENSE_FILE=   ${WRKDIR}/LICENSE

OPTIONS_DEFINE=	GECKO MONO
GECKO_DESC=     Bundle Gecko MSI package for Wine
MONO_DESC=      Bundle Mono MSI package for Wine

CONFLICTS_INSTALL?=     wine-[0-9]* wine-staging-[0-9]* wine-devel-[0-9]* \
                        i386-wine-[0-9]* i386-wine-staging-[0-9]*

EXTRACT_AFTER_ARGS=	-C / --exclude +COMPACT_MANIFEST --exclude +MANIFEST \
				--exclude +MTREE_DIRS --exclude share/licenses/'*' \
				--exclude libdata/ldconfig32/${PKGNAMEPREFIX}${PORTNAME} \
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
USES=		tar:xz desktop-file-utils
BUNDLE_LIBS=	yes

GECKO_RUN_DEPENDS=	${DATADIR}/gecko/wine_gecko-2.47-x86.msi:emulators/wine-gecko-devel
MONO_RUN_DEPENDS=	${DATADIR}/mono/wine-mono-4.7.1.msi:emulators/wine-mono-devel

# Included for OPSYS and OSVERSION
.include <bsd.port.pre.mk>

.for osrel in 11 12 13
.if ${OSREL:C/\..*//} == ${osrel}
PLIST_SUB+=	OSREL${osrel}=""
.if ${PKGNAMESUFFIX} == -devel
PLIST_SUB+=	DEVEL=""
PLIST_SUB+=	OSREL${osrel}-DEVEL=""
.else
PLIST_SUB+=	DEVEL="@comment "
PLIST_SUB+=	OSREL${osrel}-DEVEL="@comment "
.endif
.else
PLIST_SUB+=	OSREL${osrel}="@comment "
PLIST_SUB+=	OSREL${osrel}-DEVEL="@comment "
.endif
.endfor

.if ${OPSYS} != FreeBSD || (!(${OSVERSION} >= 1102000 && ${OSVERSION} < 1200000) && !(${OSVERSION} >= 1200500 && ${OSVERSION} < 1300000) && !(${OSVERSION} >= 1300003 && ${OSVERSION} < 1400000))
IGNORE=		binaries compiled for FreeBSD 11.2+, 12.0+ and -current only
DISTFILES=
.endif

do-extract:
	@${RM} -r ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} -C ${WRKDIR} --include '/usr/local/share/licenses/${DISTNAME}/LICENSE' -s '|/usr/local/share/licenses/${DISTNAME}/||g'

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS}

${PLIST}: fetch
	${TAR} -tf ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS} > /dev/null
	${TAR} -tf ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS} | ${GREP} -v '/$$\|ldconfig32' | ${SED} 's|/usr/local/||g' | sort > ${PLIST}

port-update:
	${RM} ${SLAVEDIR}/distinfo ${SLAVEDIR}/distinfo~ ${SLAVEDIR}/pkg-plist.*
.for osrel in 11 12 13
	${MAKE} fetch OSREL=${osrel} OSVERSION=${osrel}99999 _OSRELEASE=${osrel}
	${MAKE} makesum OSREL=${osrel} OSVERSION=${osrel}99999 _OSRELEASE=${osrel}
	${CAT} ${SLAVEDIR}/distinfo >> ${SLAVEDIR}/distinfo~
	${RM} ${SLAVEDIR}/distinfo
	${MAKE} pkg-plist.${osrel}${suffix:tu} PLIST=pkg-plist.${osrel}${suffix:tu} OSREL=${osrel} OSVERSION=${osrel}99999 _OSRELEASE=${osrel}
.endfor
	${SED} -e '2,$${' -e '/^TIMESTAMP/d' -e '}' distinfo~ > ${SLAVEDIR}/distinfo
	python ${FILESDIR}/mergeplist.py ${SLAVEDIR}/pkg-plist.* > ${PLIST}
	${RM} ${SLAVEDIR}/distinfo~ ${SLAVEDIR}/pkg-plist.*

.include <bsd.port.post.mk>
