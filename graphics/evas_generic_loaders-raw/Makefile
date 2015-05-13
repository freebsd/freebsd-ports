# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	raw
PORTVERSION=	1.13.2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PKGNAMEPREFIX:S/-//}/
PKGNAMEPREFIX=	evas_generic_loaders-
DISTNAME=	${PKGNAMEPREFIX}${DISTVERSION}

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Additional loader for Evas (raw)

LICENSE=	GPLv2

LIB_DEPENDS=	libefl.so:${PORTSDIR}/devel/efl \
		libraw.so:${PORTSDIR}/graphics/libraw

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		pkgconfig tar:xz
USE_LDCONFIG=	yes

BINSRC=		${WRKSRC}/src/bin/${PORTNAME}

do-build:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -C ${BINSRC}

do-install:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} -C ${BINSRC} install

.include <bsd.port.mk>
