# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	svg
PORTVERSION=	1.16.0
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PKGNAMEPREFIX:S/-//}/
PKGNAMEPREFIX=	evas_generic_loaders-
DISTNAME=	${PKGNAMEPREFIX}${DISTVERSION}

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Additional loader for Evas (svg)

LICENSE=	GPLv2

LIB_DEPENDS=	libefl.so:devel/efl

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		pkgconfig tar:xz
USE_GNOME=	librsvg2
USE_LDCONFIG=	yes

BINSRC=		${WRKSRC}/src/bin/${PORTNAME}

do-build:
	${MAKE} ${MAKE_ARGS} -C ${BINSRC}

do-install:
	${MAKE} ${MAKE_ARGS} -C ${BINSRC} install

.include <bsd.port.mk>
