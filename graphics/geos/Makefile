# Created by: Leonardo Martins <lmartins@nepe.eee.ufg.br>

PORTNAME=	geos
PORTVERSION=	3.9.2
CATEGORIES=	graphics geography
MASTER_SITES=	https://download.osgeo.org/geos/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Geometry Engine, Open Source

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang gmake libtool tar:bzip2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-configure:
	@${FIND} ${WRKSRC} -name Makefile -exec ${REINPLACE_CMD} -e '/CXXFLAGS = / s| -O2||' {} +

.include <bsd.port.mk>
