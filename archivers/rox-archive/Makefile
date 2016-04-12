# $FreeBSD$

PORTNAME=	rox-archive
PORTVERSION=	2.3
CATEGORIES=	archivers
MASTER_SITES=	SF/rox/Archive/${PORTVERSION}
DISTNAME=	archive-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Archive management tool for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:devel/py-roxlib

USES=		python tar:bzip2
NO_ARCH=	yes

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

pre-install:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
				${WRKSRC}/Archive/findrox.py
	@${FIND} ${WRKSRC} -name *.bak -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/apps
	${CP} -r ${WRKSRC}/Archive ${STAGEDIR}${PREFIX}/apps/

.include <bsd.port.mk>
