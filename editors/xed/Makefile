# Created by: shanee
# $FreeBSD$

PORTNAME=	xed
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text editor for X

USES=		imake tar:Z
USE_XORG=	xaw

pre-build:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|extern char \*malloc();|/\* extern char \*malloc(); \*/|g'
.include <bsd.port.mk>
