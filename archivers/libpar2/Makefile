# Created by: Jeff Burchell <toxic@doobie.com>
# $FreeBSD$

PORTNAME=	libpar2
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/

LICENSE=	GPLv2

MAINTAINER=	toxic@doobie.com
COMMENT=	Library for manipulating PAR2 files, extracted from par2cmdline

LIB_DEPENDS=	libsigc-2.0.so:devel/libsigc++20

GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes
USES=		pkgconfig libtool localbase compiler:c++11-lang
USE_CXXSTD=	c++11

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s/-lstdc++//g" \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
