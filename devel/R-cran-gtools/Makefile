# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtools
PORTVERSION=	3.3.1
CATEGORIES=	devel
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Various R programming tools

LICENSE=	LGPL21

USES=	cran:auto-plist

post-stage:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/R/library/gtools/libs/gtools.so

.include <bsd.port.mk>
