# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ps
PORTVERSION=	1.16.0
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PKGNAMEPREFIX:S/-//}/
PKGNAMEPREFIX=	evas_generic_loaders-
DISTNAME=	${PKGNAMEPREFIX}${DISTVERSION}

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Additional loader for Evas (ps)

LICENSE=	GPLv2

LIB_DEPENDS=	libefl.so:devel/efl \
		libspectre.so:print/libspectre

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		pkgconfig tar:xz
USE_LDCONFIG=	yes

BINSRC=		${WRKSRC}/src/bin/${PORTNAME}

do-build:
	${MAKE} ${MAKE_ARGS} -C ${BINSRC}

do-install:
	${MAKE} ${MAKE_ARGS} -C ${BINSRC} install

.include <bsd.port.mk>
