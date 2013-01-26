# $FreeBSD$

PORTNAME=	rox-archive
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	SF/rox/Archive/${PORTVERSION}
DISTNAME=	archive-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Archive management tool for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_BZIP2=	yes
USE_PYTHON=	yes

post-patch:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -r

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

pre-install:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
				${WRKSRC}/Archive/findrox.py
	@${FIND} ${WRKSRC} -name *.bak | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${PREFIX}/apps
	@${CP} -r ${WRKSRC}/Archive ${PREFIX}/apps/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/Archive

.include <bsd.port.mk>
