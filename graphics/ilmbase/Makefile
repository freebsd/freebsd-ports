# New ports collection makefile for:	ilmbase
# Date created:				2007-10-07
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ilmbase
PORTVERSION=    1.0.0
CATEGORIES=     graphics devel
MASTER_SITES=   ${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	openexr

MAINTAINER=	nork@FreeBSD.org
COMMENT=	ILM Base libraries a.k.a. Half, IlmThread, Imath and Iex

USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15

CONFIGURE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
