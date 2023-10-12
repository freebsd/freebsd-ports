PORTNAME=	varconf
PORTVERSION=	1.0.1
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	SF/worldforge/${PORTNAME}%20%28config%20lib%29/${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Configuration System for the STAGE Server

DEPRECATED=	There has been no release for most of the Worldforge libraries in the past 10 years.
EXPIRATION_DATE=2023-12-31

LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20

USES=		compiler:c++11-lib libtool pathfix pkgconfig tar:bzip2
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README COPYING AUTHORS THANKS NEWS
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
