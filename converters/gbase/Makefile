# New ports collection makefile for:	gbase
# Date created:				Fri Sep  7 22:08:24 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gbase
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.hibernaculum.net/download/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A program to convert between the 4 common bases used in programming

PLIST_FILES=	bin/gbase
USE_X_PREFIX=	yes
USE_GNOME=	gtk12

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gbase ${PREFIX}/bin

.include <bsd.port.mk>
