# New ports collection makefile for:	gbase
# Date created:				Fri Sep  7 22:08:24 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gbase
PORTVERSION=	0.5
CATEGORIES=	converters
MASTER_SITES=	http://www.hibernaculum.net/download/

MAINTAINER=	pat@FreeBSD.org

USE_X_PREFIX=	yes
USE_GTK=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gbase ${PREFIX}/bin

.include <bsd.port.mk>
