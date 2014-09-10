# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	evas
PORTVERSION=	1.7.9
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Hardware accelerated canvas API (meta-port)

NO_BUILD=	yes
USE_EFL=	evas

OPTIONS_MULTI=	ENGINES
OPTIONS_MULTI_ENGINES=BUFFER OPENGL SDL X11
OPTIONS_DEFINE=	BMP EET GENERIC GIF ICO JPEG \
		PNG PMAPS PSD SVG TGA TIFF WBMP XPM
OPTIONS_DEFAULT=BUFFER OPENGL X11 \
		BMP EET GENERIC GIF ICO JPEG \
		PNG PMAPS PSD TGA TIFF WBMP XPM

.for NODE in ${OPTIONS_MULTI_ENGINES}
${NODE}_DESC=	Install ${NODE:tl} engine
.endfor

.for NODE in ${OPTIONS_DEFINE}
${NODE}_DESC=	Install ${NODE:tl} loader
.endfor

.include <bsd.port.options.mk>

.for NODE in ${OPTIONS_MULTI_ENGINES}
.  if ${PORT_OPTIONS:M${NODE}}
USE_EFL_EVAS_ENGINES+=	${NODE:tl}
.  endif
.endfor

.for NODE in ${OPTIONS_DEFINE}
.  if ${PORT_OPTIONS:M${NODE}}
USE_EFL_EVAS_LOADERS+=	${NODE:tl}
.  endif
.endfor

do-install:
	${DO_NADA}

.include <bsd.port.mk>
