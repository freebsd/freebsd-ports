# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	varconf
PORTVERSION=	1.0.1
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28config%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Configuration System for the STAGE Server

LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README COPYING AUTHORS THANKS NEWS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
