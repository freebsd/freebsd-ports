# New ports collection makefile for:	sfml
# Date created:		07 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sfml
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	SFML-${PORTVERSION}-sdk-linux-32

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple and Fast Multimedia Library

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		openal.0:${PORTSDIR}/audio/openal \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_XORG=	x11 xrandr
USE_GL=		gl glu
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/SFML-${PORTVERSION}

PORTDOCS=	*

post-extract:
	@${RM} ${WRKSRC}/lib/*

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "*" ${DOCSDIR}/
.endif

.include <bsd.port.mk>
