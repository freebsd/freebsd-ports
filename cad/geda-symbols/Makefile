# New ports collection makefile for:	geda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	symbols
PORTVERSION=	20020825
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/ \
		http://www.tinkerbox.org/projects/files/gEDA/
DISTNAME=	geda-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bruno@tinkerbox.org

#USE_AUTOCONF=	yes

GNU_CONFIGURE=	yes
AUTOCONF=	autoconf

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
