# New ports collection makefile for:	excido
# Date created:				19 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	excido
PORTVERSION=	0.1.5c
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/excido/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A portable fast-paced 3d shooter

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		physfs.1:${PORTSDIR}/devel/physfs \
		alut.1:${PORTSDIR}/audio/freealut

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	image sdl ttf

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
