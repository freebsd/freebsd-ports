# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdf
PORTVERSION=	1.12.0
PORTREVISION=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PKGNAMEPREFIX:S/-//}/
PKGNAMEPREFIX=	evas_generic_loaders-
DISTNAME=	${PKGNAMEPREFIX}${DISTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Additional loader for Evas (pdf)

LICENSE=	GPLv2

LIB_DEPENDS=	libefl.so:${PORTSDIR}/devel/efl \
		libpoppler.so:${PORTSDIR}/graphics/poppler

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		compiler:c11 pkgconfig tar:xz
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

BINSRC=		${WRKSRC}/src/bin/${PORTNAME}

do-build:
	${MAKE} ${MAKE_ARGS} -C ${BINSRC}

do-install:
	${MAKE} ${MAKE_ARGS} -C ${BINSRC} install

.include <bsd.port.mk>
