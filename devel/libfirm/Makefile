# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	libfirm
PORTVERSION=	1.21.0
CATEGORIES=	devel lang
MASTER_SITES=	SF

MAINTAINER=	sperber@FreeBSD.org
COMMENT=	Graph-based SSA intermediate representation library for compilers

OPTIONS_DEFINE=	DEBUG

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USE_AUTOTOOLS=	autoconf
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig

OPTIONS_DEFINE=	DEBUG

DEBUG_CONFIGURE_ENABLE=	debug

.include <bsd.port.mk>
