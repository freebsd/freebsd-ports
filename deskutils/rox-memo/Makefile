# $FreeBSD$

PORTNAME=	rox-memo
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/rox/Memo/${PORTVERSION}
DISTNAME=	memo-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Appointment/TODO management for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_BZIP2=	yes
USE_PYTHON=	yes

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
