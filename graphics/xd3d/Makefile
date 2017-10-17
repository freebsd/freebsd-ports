# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	xd3d
PORTVERSION=	8.3.1
PORTREVISION=	12
CATEGORIES=	graphics math
MASTER_SITES=	http://www.cmap.polytechnique.fr/~jouve/xd3d/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Simple scientific visualization tool

LICENSE=	GPLv2

#--------------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_IMAGEMAGICK	:	if you don't need to export bitmap images
#				in gif or png format;
#
# - WITHOUT_GIFSICLE	:	if you don't need to generate animated gifs;
#
# - MEMORY_XD3D		:	Max memory for xd3d (MBytes, 64 by default)
#
# - F77			:	don't use the default fortran compiler;
# - FFLAGS		:	fortran compiler's flags (-O by default).
#--------------------------------------------------------------------------

OPTIONS_DEFINE=	DOCS EXAMPLES

.if !defined(WITHOUT_IMAGEMAGICK)
RUN_DEPENDS+=	convert:graphics/ImageMagick
.endif
.if !defined(WITHOUT_GIFSICLE)
RUN_DEPENDS+=	gifsicle:graphics/gifsicle
.endif

MASTER_SITES_BACKUP=	http://pompo.net/ports/

REINPLACE_ARGS=	-i ""
FETCH_ARGS=
FETCH_BEFORE_ARGS=	-R -o ${DISTDIR}/${DISTFILES}

USES=		fortran
USE_XORG=	x11 xpm
FFLAGS+=	-O
MEMORY_XD3D?=	64

.if defined(LANG) && ${LANG:Mfr*} != ""
XD3D_LANG=	FRANCAIS
.else
XD3D_LANG=	ENGLISH
.endif

DOCS=		BUGS CHANGELOG FAQ FORMATS INSTALL README Manuals/formats.txt	\
		Manuals/xd3d_doc.pdf Manuals/xgraphic_doc.pdf

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	${FETCH_CMD} ${FETCH_BEFORE_ARGS}			\
		${MASTER_SITES}download.php?file=${DISTFILES}	\
	|| ${FETCH_CMD} ${FETCH_BEFORE_ARGS} ${MASTER_SITES_BACKUP}${DISTFILES}
.endif

pre-configure:
	${CP} ${WRKSRC}/RULES.freeBSD ${WRKSRC}/RULES
	${REINPLACE_CMD} -e "s|%%WRKSRC%%|${WRKSRC}|"		\
		-e "s|%%PREFIX%%|${PREFIX}|"			\
		-e "s|%%X11BASE%%|${LOCALBASE}|"		\
		-e "s|%%LANG%%|${XD3D_LANG}|"			\
		-e "s|%%MEMORY_XD3D%%|${MEMORY_XD3D}|"		\
		-e "s|%%F77%%|${F77}|"				\
		-e "s|%%FFLAGS%%|${FFLAGS}|"			\
		-e "s|%%CC%%|${CC}|"				\
		-e "s|%%CFLAGS%%|${CFLAGS}|"			\
		${WRKSRC}/RULES

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
. endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -Rp ${WRKSRC}/Examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
