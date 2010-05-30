# New ports collection makefile for:	Cenon
# Date created:				16 Nov 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cenon
PORTVERSION=	3.83
PORTREVISION=	2
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.vhf-group.com/vhfInterservice/download/source/
DISTNAME=	Cenon-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A vector graphics tool for GNUstep

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/Cenon
FULLVERSION=	3.82
CENON_LIB_DIR=	${GNUSTEP_LOCAL_ROOT}/Library/Cenon

OPTIONS=	FULL_LIBRARY	"Install complete Cenon Library" off

.include <bsd.port.pre.mk>

.if defined(WITH_FULL_LIBRARY) || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX}
PLIST_SUB+=	FULL=""
.else
PLIST_SUB+=	FULL="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} '/cp -R Library/d' ${WRKSRC}/GNUmakefile.postamble
	@${RM} -f ${WRKSRC}/Library/Cenon/Devices/gerber/gerber.doc
	@${FIND} ${WRKSRC}/Library -name COPYING -delete

post-install:
.if defined(WITH_FULL_LIBRARY)
	${TAR} xyvf ${_DISTDIR}/CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX} \
		-C ${GNUSTEP_LOCAL_ROOT}/Library/ --exclude COPYING
	@${CHOWN} -R root:wheel ${CENON_LIB_DIR}
	@${CHMOD} -R u=rwX,go=rX ${CENON_LIB_DIR}
	@${CHMOD} 444 ${CENON_LIB_DIR}/INSTALL
	${INSTALL_DATA} ${WRKSRC}/Library/Cenon/README ${CENON_LIB_DIR}/
.else
	${CP} -R ${WRKSRC}/Library/Cenon ${GNUSTEP_LOCAL_ROOT}/Library/
.endif
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${CENON_LIB_DIR}/

.include <bsd.port.post.mk>
