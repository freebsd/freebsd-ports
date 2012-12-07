# Created by: Richard Neese
# $FreeBSD$

PORTNAME=	sphinx3
PORTVERSION=	0.7
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system

LIB_DEPENDS=	sphinxbase:${PORTSDIR}/audio/sphinxbase

BROKEN=		does not compile

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=libtool

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/sphinxbase
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
