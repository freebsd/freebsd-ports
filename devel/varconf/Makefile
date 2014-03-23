# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	varconf
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28config%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Configuration System for the STAGE Server

LIB_DEPENDS=	libsigc-2.0.so:${PORTSDIR}/devel/libsigc++20

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		libtool pathfix pkgconfig compiler:c++11-lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README COPYING AUTHORS THANKS NEWS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
