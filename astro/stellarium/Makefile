# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	stellarium
PORTVERSION=	0.12.4
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/Stellarium-sources/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY:=	${DISTFILES}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	3D photo-realistic sky renderer (planetarium)

LICENSE=	GPLv2

USES=		cmake gettext iconv
USE_GL=		glu
USE_QT4=	moc_build rcc_build uic_build qmake_build \
		corelib gui network opengl script
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=		MORE_STARS MULTIMEDIA DOCS
OPTIONS_DEFAULT=	MULTIMEDIA
MORE_STARS_DESC=	Install extra star catalogs (1.2GB)
MULTIMEDIA_DESC=	Sound and video support (via Phonon)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMORE_STARS}
.  for i in 4 5 6 7 8
MASTER_SITES+=	SF/${PORTNAME}/Extra-data-files/stars${i}:stars${i}
.  endfor
DISTFILES+=	stars_4_1v0_0.cat:stars4 stars_5_2v0_0.cat:stars5 \
		stars_6_2v0_0.cat:stars6 stars_7_2v0_0.cat:stars7 \
		stars_8_2v0_0.cat:stars8
PLIST_SUB+=	MORE_STARS=""
.else
PLIST_SUB+=	MORE_STARS="@comment "
.endif

.if ${PORT_OPTIONS:MMULTIMEDIA}
USE_QT4+=	phonon
.else
CMAKE_ARGS+=	-DENABLE_SOUND:BOOL=OFF
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e '/QTTEST/d' ${WRKSRC}/CMakeLists.txt
# Avoid picking up the wrong `fixx11h.h' (`x11/kdelibs3' port installs one
# that does not handle FontChange)
	${GREP} -Rl --null fixx11h\\.h ${WRKSRC}/src ${WRKSRC}/plugins | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/fixx11h\.h/fixx11qt4h.h/'
	cd ${WRKSRC}/src/core/external && ${MV} fixx11h.h fixx11qt4h.h

post-install:
.if ${PORT_OPTIONS:MMORE_STARS}
	${INSTALL_DATA} ${DISTDIR}/stars_[45678]_[12]v0_0.cat \
		${STAGEDIR}${DATADIR}/stars/default
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
