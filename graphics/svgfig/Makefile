# $FreeBSD$

PORTNAME=	SVGFig
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draw mathematical figures in SVG using Python

BROKEN=		Unfetchable (google code has gone away)

WRKSRC=		${WRKDIR}/${PORTNAME:tl}

USES=		python tar:tgz
USE_PYTHON=	distutils autoplist

post-patch:
	@${REINPLACE_CMD} -e 's|1.1.2|${PORTVERSION}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
