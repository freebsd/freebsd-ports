# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	libfirm
PORTVERSION=	1.21.0
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	SF

MAINTAINER=	sperber@FreeBSD.org
COMMENT=	Graph-based SSA intermediate representation library for compilers

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.mk>
