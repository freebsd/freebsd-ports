# New ports collection makefile for:	xed
# Date created:		28 Jul 1996
# Whom:			shanee
#
# $FreeBSD$
#

PORTNAME=	xed
PORTVERSION=	1.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text editor for X

USE_IMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=yes
MAN1=		xed.1

pre-build:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|extern char \*malloc();|/\* extern char \*malloc(); \*/|g'
.include <bsd.port.mk>
