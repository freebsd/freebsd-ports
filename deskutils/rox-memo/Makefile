# $FreeBSD$

PORTNAME=	rox-memo
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF/rox/Memo/${PORTVERSION}
DISTNAME=	memo-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Appointment/TODO management for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:x11-fm/rox-filer \
		${PYTHON_PKGNAMEPREFIX}roxlib>=0:devel/py-roxlib

USES=		python:2.7 shebangfix tar:bzip2
SHEBANG_FILES=	Memo/AppRun Memo/AppletRun

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

pre-install:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
				${WRKSRC}/Memo/findrox.py
	@${FIND} ${WRKSRC} -name *.bak -delete

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/apps
	${CP} -r ${WRKSRC}/Memo ${STAGEDIR}${PREFIX}/apps/

.include <bsd.port.mk>
