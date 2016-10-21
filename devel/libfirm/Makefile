# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	libfirm
PORTVERSION=	1.21.0
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graph-based SSA intermediate representation library for compilers

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USES=		autoreconf gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.mk>
