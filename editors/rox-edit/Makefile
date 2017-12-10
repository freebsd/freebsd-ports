# $FreeBSD$

PORTNAME=	rox-edit
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/rox/Edit/${PORTVERSION}
DISTNAME=	edit-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Text editor for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:x11-fm/rox-filer \
		${PYTHON_PKGNAMEPREFIX}roxlib>=0:devel/py-roxlib

USES=		python:2.7 tar:bzip2

post-extract:
	@${FIND} ${WRKSRC} -name .cvsignore | ${XARGS} ${RM}
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -r

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

pre-install:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
			${WRKSRC}/Edit/findrox.py
	@${FIND} ${WRKSRC} -name *.bak | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/apps
	${CP} -r ${WRKSRC}/Edit ${STAGEDIR}${PREFIX}/apps/

.include <bsd.port.mk>
