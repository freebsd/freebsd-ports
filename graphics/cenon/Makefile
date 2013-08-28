# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	cenon
PORTVERSION=	4.0.2
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.vhf-group.com/vhf-interservice/download/source/
DISTNAME=	Cenon-${MAINVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	A vector graphics tool for GNUstep

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Cenon
MAINVERSION=	4.0.2
FULLVERSION=	4.0.0
CENON_LIB_DIR=	${GNUSTEP_LOCAL_ROOT}/Library/Cenon

OPTIONS_DEFINE=	FULL_LIBRARY
FULL_LIBRARY_DESC=	Install complete Cenon Library

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFULL_LIBRARY} || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX}
PLIST_SUB+=	FULL=""
PLIST_SUB+=	LITE="@comment "
.else
PLIST_SUB+=	FULL="@comment "
PLIST_SUB+=	LITE=""
.endif

post-extract:
	@${REINPLACE_CMD} '/cp -R Library/d' ${WRKSRC}/GNUmakefile.postamble
	@${RM} -f ${WRKSRC}/Library/Cenon/Devices/gerber/gerber.doc
	@${FIND} ${WRKSRC}/Library -name COPYING -delete

post-install:
.if ${PORT_OPTIONS:MFULL_LIBRARY}
	${TAR} xyvf ${_DISTDIR}/CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX} \
		-C ${GNUSTEP_LOCAL_ROOT}/Library/ --exclude COPYING
	@${CHOWN} -R root:wheel ${CENON_LIB_DIR}
	@${CHMOD} -R u=rwX,go=rX ${CENON_LIB_DIR}
	${INSTALL_DATA} ${WRKSRC}/Library/Cenon/README ${CENON_LIB_DIR}/
.else
	${CP} -R ${WRKSRC}/Library/Cenon ${GNUSTEP_LOCAL_ROOT}/Library/
.endif
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${CENON_LIB_DIR}/

.include <bsd.port.mk>
