# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wine
PORTVERSION=	1.7.4
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/dbn/repos/wine/${DIST_SUBDIR}/${PORTVERSION}
PKGNAMEPREFIX=	i386-
PKGNAMESUFFIX=	-devel
DISTNAME=	${PKGNAME}
EXTRACT_SUFX=	.txz
DIST_SUBDIR=	freebsd:${OSREL:C/\..*//}:x86:64

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	32bit Microsoft Windows compatibility environment for 64bit FreeBSD

LICENSE=        LGPL21 LGPL3
LICENSE_COMB=   dual
LICENSE_FILE=   ${WRKDIR}/LICENSE

OPTIONS_DEFINE=	GECKO MONO
GECKO_DESC=     Bundle Gecko MSI package for Wine
MONO_DESC=      Bundle Mono MSI package for Wine

CONFLICTS_INSTALL=	i386-wine-1.4* i386-wine-1.6* wine-[0-9]*

EXTRACT_AFTER_ARGS=	-C / --exclude +COMPACT_MANIFEST --exclude +MANIFEST \
				--exclude +MTREE_DIRS --exclude share/licenses/'*' \
				--exclude libdata/ldconfig32/${UNIQUENAME} \
				-s '|/usr/local|${STAGEDIR}${PREFIX}|gs'
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	wine only runs on x86 architecture
PKGINSTALL=	${.CURDIR}/files/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USE_LDCONFIG32=	${PREFIX}/lib32 ${PREFIX}/lib32/wine
USE_XZ=		yes

.include <bsd.port.pre.mk>

.if !(${OSVERSION} >= 803000 && ${OSVERSION} < 900000) && !(${OSVERSION} >= 901000 && ${OSVERSION} < 1000000)
IGNORE=		binaries compiled for FreeBSD 8.3+ and 9.1+ only
DISTFILES=
.endif

.if ${PORT_OPTIONS:MGECKO}
RUN_DEPENDS+=   ${DATADIR}/gecko/wine_gecko-2.24-x86.msi:${PORTSDIR}/emulators/wine-gecko-devel
.endif

.if ${PORT_OPTIONS:MMONO}
RUN_DEPENDS+=   ${DATADIR}/mono/wine-mono-0.0.8.msi:${PORTSDIR}/emulators/wine-mono
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} -C ${WRKDIR} --include '/usr/local/share/licenses/${PKGNAME}/LICENSE' -s '|/usr/local/share/licenses/${PKGNAME}/||g'

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS}

pkg-plist: extract
	${TAR} -tf ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS} | ${GREP} -v '/$$' | ${SED} 's|/usr/local/||g' | sort > ${WRKDIR}/pkg-plist
	${TAR} -tf ${_DISTDIR}/${EXTRACT_ONLY} ${EXTRACT_AFTER_ARGS} | ${GREP} '/$$' | ${SED} 's|/usr/local/\(.*\)/$$|@dirrm \1|g' | sort -r >> ${WRKDIR}/pkg-plist
	${REINPLACE_CMD} -e 's|@dirrm share/applications|@dirrmtry share/applications|' -e 's|/$$||g' ${WRKDIR}/pkg-plist
	${MV} ${WRKDIR}/pkg-plist ${PLIST}

.include <bsd.port.post.mk>
