# Created by: Richard Neese
# $FreeBSD$

PORTNAME=	sphinx3
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system

LIB_DEPENDS=	libsphinxbase.so:audio/sphinxbase

USES=		gmake pathfix libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_CSTD=	gnu99
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include #-I${LOCALBASE}/include/sphinxbase
CXXFLAGS+=	-I${LOCALBASE}/include #-I${LOCALBASE}/include/sphinxbase
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libs3decoder.so

.include <bsd.port.mk>
