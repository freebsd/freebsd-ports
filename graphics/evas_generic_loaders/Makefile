# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evas_generic_loaders
PORTVERSION=	1.16.0
CATEGORIES=	graphics enlightenment

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Additional loaders for Evas (meta-port)

USES=		metaport

OPTIONS_DEFINE=	GST PDF PS RAW SVG XCF
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

.for NODE in ${OPTIONS_DEFINE}
${NODE}_DESC=	Install ${NODE:tl} loader
${NODE}_RUN_DEPENDS+=	${LOCALBASE}/lib/evas/utils/evas_image_loader.${NODE:tl}:graphics/evas_generic_loaders-${NODE:tl}
.endfor

.include <bsd.port.mk>
