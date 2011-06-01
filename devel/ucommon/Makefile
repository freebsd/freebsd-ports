# New ports collection Makefile for:	ucommon
# Date created:				21 February 2011
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	ucommon
PORTVERSION=	5.0.1
CATEGORIES=	devel
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	commoncpp

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A very light-weight C++ design patternlibrary

USE_GNOME=	pkgconfig gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${PTHREAD_LIBS}"

MAN1=	args.1 scrub.1 mdsum.1 zerofill.1 ucommon-config.1

.include <bsd.port.mk>
