# Created by: ijliao
# $FreeBSD$

PORTNAME=	guile-lib
PORTVERSION=	0.2.2
CATEGORIES=	devel scheme
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Repository of useful code written in Guile Scheme

BUILD_DEPENDS=	guile:lang/guile
RUN_DEPENDS=	guile:lang/guile

BROKEN_armv6=		fails to compile: stack overflow
BROKEN_armv7=		fails to compile: stack overflow

USES=		gmake
GNU_CONFIGURE=	yes

INFO=	guile-library

.include <bsd.port.mk>
