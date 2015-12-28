# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cenon
PORTVERSION=	4.0.2
PORTREVISION=	3
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.cenon.zone/download/source/
DISTNAME=	Cenon-${MAINVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Vector graphics tool for GNUstep

USES=	tar:bzip2 gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/Cenon
MAINVERSION=	4.0.2
FULLVERSION=	4.0.0
CENON_LIB_DIR=	${GNUSTEP_SYSTEM_ROOT}/Library/Cenon

OPTIONS_DEFINE=	FULL_LIBRARY
FULL_LIBRARY_DESC=	Install complete Cenon Library

.include <bsd.port.options.mk>

DISTFILES+=	CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX}

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DOMAIN|#GNUSTEP_INSTALLATION_DOMAIN|' \
		${WRKSRC}/GNUmakefile

pre-install:
	${MKDIR} ${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Library/
	${TAR} -xyvf ${_DISTDIR}/CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX} \
		-C ${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Library/ \
		--exclude COPYING --exclude '._*'

.include <bsd.port.mk>
