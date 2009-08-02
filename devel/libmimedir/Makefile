# New ports collection makefile for: 	libmimedir
# Date created:                March 2004
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	libmimedir
PORTVERSION=	0.5.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing RFC2425 MIME Directory Profile information

USE_GNOME=	gnometarget
USE_BISON=	build
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

regression-test:
	cd ${WRKSRC} && ./test

.include <bsd.port.mk>
