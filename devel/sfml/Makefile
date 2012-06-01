# New ports collection makefile for:	sfml
# Date created:		07 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sfml
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	SFML-${PORTVERSION}-sdk-linux-32

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple and Fast Multimedia Library

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_OPENAL=	al
USE_XORG=	x11 xrandr
USE_GL=		gl glu
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/SFML-${PORTVERSION}

PORTDOCS=	*

PORTSCOUT=	limit:[^c]$$

post-extract:
	@${RM} -f ${WRKSRC}/lib/*
	@${FIND} ${WRKSRC}/samples/bin/ -type f -maxdepth 1 -delete

post-install:
.for lib in audio graphics network system window
	@${LN} -s libsfml-${lib}.so.${PORTVERSION} ${PREFIX}/lib/libsfml-${lib}.so.${PORTVERSION:C/^([0-9]).*/\1/}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "*" ${DOCSDIR}/
.endif

.include <bsd.port.mk>
