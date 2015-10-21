# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.28 2010/11/15 14:12:13 kwm Exp $

PORTNAME=	cairo
PORTVERSION=	1.10.0
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 3 bindings for Cairo

USES=		pkgconfig python:3 shebangfix tar:bzip2 waf
USE_GNOME=	cairo
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SHEBANG_FILES=	examples/*.py examples/*/*.py test/*.py

PLIST_SUB+=	PYTVER=${PYTHON_VER:S/.//}

post-patch:
	@${REINPLACE_CMD} -e 's|python %s|${PYTHON_CMD} %s|g' \
		${WRKSRC}/test/examples_test.py

pre-configure:
# Run waf configure twice, once to extract waflib and patch and then actual configure
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} || :
	@cd ${WRKSRC}/.waf3-1.6.4-e3c1e08604b18a10567cfcd2d02eb6e6/ && \
		${PATCH} -p1 < ${FILESDIR}/pycairo-1.10.0-waf-py3_4.patch

post-install:
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/cairo/__init__.py[co]
	@cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
	@cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cairo/_cairo.so

.include <bsd.port.mk>
