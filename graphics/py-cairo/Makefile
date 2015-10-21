# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.28 2010/11/15 14:12:13 kwm Exp $

PORTNAME=	cairo
PORTVERSION=	1.10.0
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py2${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 2 bindings for Cairo

USES=		pkgconfig python:2 shebangfix tar:bzip2 waf
USE_GNOME=	cairo
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	PYTHON=${LOCALBASE}/bin/${PYTHON_CMD} \
		PREFIX=${PREFIX}

SHEBANG_FILES=	examples/*.py examples/*/*.py test/*.py

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
	@cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cairo/_cairo.so

.include <bsd.port.mk>
