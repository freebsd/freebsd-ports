# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ksmp3play
PORTVERSION=	0.5.2.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based MP3 player

LIB_DEPENDS=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg

GNU_CONFIGURE=	yes
USES=		pathfix
USE_SDL=	sdl
NO_WRKSUBDIR=	yes
EXTRACT_AFTER_ARGS=	--exclude CVS

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
