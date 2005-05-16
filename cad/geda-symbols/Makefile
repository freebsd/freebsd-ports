# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	geda-symbols
PORTVERSION=	20050313
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/

MAINTAINER=	bruno@tinkerbox.org
COMMENT=	gEDA symbols

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	@${TOUCH} ${PREFIX}/share/gEDA/sym/local/.keep_me

.include <bsd.port.mk>
