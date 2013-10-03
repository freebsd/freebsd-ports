# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.28 2010/11/15 14:12:13 kwm Exp $

PORTNAME=	cairo
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 3 bindings for Cairo

USE_BZIP2=	yes
USE_PYTHON=	3
USES=		pkgconfig shebangfix
USE_GNOME=	cairo
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	PYTHON=${LOCALBASE}/bin/python3 \
		PREFIX=${PREFIX}

python_OLD_CMD?=	/usr/bin/env python
python_CMD?=		${LOCALBASE}/bin/python3
SHEBANG_FILES=		examples/*.py examples/*/*.py waf test/*.py

do-configure:
	@cd ${WRKSRC} && ${ENV} ${CONFIGURE_ENV} ./waf configure

do-build:
	@cd ${WRKSRC} && ./waf

do-install:
	@cd ${WRKSRC} && ./waf install

.include <bsd.port.mk>
