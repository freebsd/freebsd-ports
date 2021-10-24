PORTNAME=	sfsexp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1-18
DISTVERSIONSUFFIX=	-gc11b849
CATEGORIES=	devel

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Small Fast S-Expression Library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE_LGPL

USES=		autoreconf libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	mjsottile
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pc \
	  ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
