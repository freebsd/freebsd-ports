# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	evas_generic_loaders
PORTVERSION=	1.13.2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Additional loaders for Evas (meta-port)

NO_BUILD=	yes

OPTIONS_DEFINE=	GST PDF PS RAW SVG XCF
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

.for NODE in ${OPTIONS_DEFINE}
${NODE}_DESC=	Install ${NODE:tl} loader
.endfor

.include <bsd.port.options.mk>

.for NODE in ${OPTIONS_DEFINE}
.  if ${PORT_OPTIONS:M${NODE}}
RUN_DEPENDS+=	${LOCALBASE}/lib/evas/utils/evas_image_loader.${NODE:tl}:${PORTSDIR}/graphics/evas_generic_loaders-${NODE:tl}
.  endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.mk>
