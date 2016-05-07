# $FreeBSD$

PORTNAME=	roxlib
PORTVERSION=	2.0.6
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	SF/rox/ROX-Lib/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rox-lib2-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Python libraries for ROX

USES=		python tar:bzip2
USE_GNOME=	pygtk2:run

RUN_DEPENDS=	${LOCALBASE}/bin/rox:x11-fm/rox-filer

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	@cd ${WRKSRC}/ROX-Lib2/python && ${PYTHON_CMD} make_docs.py

do-install:
	${CP} -r ${WRKSRC}/ROX-Lib2 ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
