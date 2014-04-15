# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.28 2010/11/15 14:12:13 kwm Exp $

PORTNAME=	cairo
PORTVERSION=	1.10.0
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 3 bindings for Cairo

USE_PYTHON=	3
USES=		pkgconfig shebangfix tar:bzip2
USE_GNOME=	cairo
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

python_OLD_CMD?=	/usr/bin/env python
python_CMD?=		${LOCALBASE}/bin/python${PYTHON_VER}
SHEBANG_FILES=		examples/*.py examples/*/*.py test/*.py

PLIST_SUB+=	PYTVER=${PYTHON_VER:S/.//}

post-patch:
	@${REINPLACE_CMD} -e 's|python %s|${PYTHON_CMD} %s|g' \
		${WRKSRC}/test/examples_test.py

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${PYTHON_CMD} \
		./waf configure

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} ./waf

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} ./waf install --destdir=${STAGEDIR}

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/cairo/__init__.py[co]
	@cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
	@cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cairo/_cairo.so

.include <bsd.port.mk>
