# New ports collection makefile for:  bugsx
# Date created:  7 December 1997
# Whom:  Don Croyle <croyle@gelemna.org>
#
# $FreeBSD$
#

PORTNAME=	bugsx
PORTVERSION=	1.08
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
DISTNAME=	bugsx108
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Breed bugs using genetic algorithims

USE_IMAKE=	yes
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/bugsx
# isn't really gzipped
EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
MAN1=		bugsx.1
PLIST_FILES=	bin/bugsx

post-install:
	${STRIP_CMD} ${PREFIX}/bin/bugsx

.include <bsd.port.mk>
