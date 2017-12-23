# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	stellarium
PORTVERSION=	0.12.9
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/Stellarium-sources/${PORTVERSION}
PKGNAMESUFFIX=	-qt4
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${_DISTFILES:Nstars_*.cat}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	3D photo-realistic sky renderer (planetarium)

LICENSE=	GPLv2+

CONFLICTS_INSTALL=	${PORTNAME}-0.17.*
PORTSCOUT=	limit:^0\.12\.			# track only 0.12.x (legacy)

USES=		cmake gettext iconv
USE_QT4=	moc_build rcc_build uic_build qmake_build \
		corelib gui network opengl

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=		DOCS MORE_STARS MULTIMEDIA SCRIPTING TEXTURES
OPTIONS_DEFAULT=	MULTIMEDIA SCRIPTING TEXTURES

MORE_STARS_DESC=	Install extra star catalogs (1.0GB)
TEXTURES_DESC=		Install better quality textures
MULTIMEDIA_DESC=	Sound and video support (via Phonon)
SCRIPTING_DESC=		Scripting support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMORE_STARS} || ${.TARGETS:Mmakesum}
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

.if ${PORT_OPTIONS:MTEXTURES} || ${.TARGETS:Mmakesum}
MASTER_SITES+=	SF/${PORTNAME}/Extra-data-files/textures:gfx
DISTFILES+=	textures-1K.zip:gfx
PLIST_SUB+=	TEXTURES=""
.else
PLIST_SUB+=	TEXTURES="@comment "
.endif

.if ${PORT_OPTIONS:MMULTIMEDIA}
USE_QT4+=	phonon
.else
CMAKE_ARGS+=	-DENABLE_SOUND:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MSCRIPTING}
USE_QT4+=	script
PLIST_SUB+=	SCRIPTS=""
.else
CMAKE_ARGS+=	-DENABLE_SCRIPTING:BOOL=OFF
PLIST_SUB+=	SCRIPTS="@comment "
.endif

post-patch: .SILENT
# Avoid picking up the wrong `fixx11h.h' (`x11/kdelibs3' port installs one
# that does not handle FontChange)
	${GREP} -Rl --null fixx11h\\.h ${WRKSRC}/src ${WRKSRC}/plugins | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/fixx11h\.h/fixx11qt4h.h/'
	cd ${WRKSRC}/src/core/external && ${MV} fixx11h.h fixx11qt4h.h

post-install-MORE_STARS-on:
	${INSTALL_DATA} ${DISTDIR}/stars_[45678]_[12]v0_1.cat \
		${STAGEDIR}${DATADIR}/stars/default

post-install-TEXTURES-on:
	(cd ${WRKDIR} && for f in *.png; do \
		new=`${STAT} -f '%z' $$f` ; \
		existing=`${STAT} -qf '%z' \
			${STAGEDIR}${DATADIR}/textures/$$f || \
			${ECHO_CMD} 0` ; \
		${TEST} $$new -gt $$existing || continue ; \
		${ECHO_CMD} "-- Replacing texture: $$f\
			(has larger file size or missing)" ; \
		${INSTALL_DATA} $$f ${STAGEDIR}${DATADIR}/textures ; \
	done)
	@${REINPLACE_CMD} -e '1410s|nomap|vesta|' \
		${STAGEDIR}${DATADIR}/data/ssystem.ini

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
