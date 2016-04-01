# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	excido
PORTVERSION=	0.1.5c
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	https://icculus.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable fast-paced 3D shooter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libphysfs.so:devel/physfs

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GL=		yes
USE_SDL=	image sdl ttf
USES=		gmake openal:al,alut tar:bzip2

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/excido ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/data ; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
