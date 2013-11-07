# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdf
PORTVERSION=	1.7.9
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	evas_generic_loaders-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Additional loader for Evas (pdf)

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler.so:${PORTSDIR}/graphics/poppler

USES=		pkgconfig
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina
USE_LDCONFIG=	yes

BINSRC=		${WRKSRC}/src/bin/${PORTNAME}

do-build:
	${MAKE} ${MAKE_ARGS} -C ${BINSRC}

do-install:
	${MAKE} ${MAKE_ARGS} -C ${BINSRC} install

.include <bsd.port.mk>
