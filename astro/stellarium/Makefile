# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	stellarium
PORTVERSION=	0.13.1
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/Stellarium-sources/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${_DISTFILES:Nstars_*.cat\:stars?}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	3D photo-realistic sky renderer (planetarium)

LICENSE=	GPLv2

USES=		cmake gettext iconv
USE_QT5=	qmake_build buildtools_build linguisttools_build \
		core concurrent declarative
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=		MORE_STARS HR_TEXTURES MULTIMEDIA DOCS
OPTIONS_DEFAULT=	MULTIMEDIA
MORE_STARS_DESC=	Install extra star catalogs (1.0GB)
HR_TEXTURES_DESC=	Install high-resolution textures
MULTIMEDIA_DESC=	Sound and video support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMORE_STARS}
.  for i in 4 5 6 7 8
MASTER_SITES+=	SF/${PORTNAME}/Extra-data-files/stars${i}:stars${i}
.  endfor
DISTFILES+=	stars_4_1v0_1.cat:stars4 stars_5_2v0_1.cat:stars5 \
		stars_6_2v0_1.cat:stars6 stars_7_2v0_1.cat:stars7 \
		stars_8_2v0_1.cat:stars8
PLIST_SUB+=	MORE_STARS=""
.else
PLIST_SUB+=	MORE_STARS="@comment "
.endif

.if ${PORT_OPTIONS:MHR_TEXTURES}
MASTER_SITES+=	SF/${PORTNAME}/textures:gfx
DISTFILES+=	textures-1K.zip:gfx milkyway.zip:gfx	# yes, in this order
.endif

.if ${PORT_OPTIONS:MMULTIMEDIA}
USE_QT5+=	multimedia
.else
CMAKE_ARGS+=	-DENABLE_SOUND:BOOL=OFF
.endif

post-patch:
	@${REINPLACE_CMD} -e 's, -Wno-unused-result,,' ${WRKSRC}/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MMORE_STARS}
	${INSTALL_DATA} ${DISTDIR}/stars_[45678]_[12]v0_1.cat \
		${STAGEDIR}${DATADIR}/stars/default
.endif
.if ${PORT_OPTIONS:MHR_TEXTURES}
	${INSTALL_DATA} ${WRKDIR}/*.png ${STAGEDIR}${DATADIR}/textures
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
