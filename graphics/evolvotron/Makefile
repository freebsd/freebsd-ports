# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	evolvotron
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF \
		SF/nemysisfreebsdp/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}_icons${EXTRACT_SUFX}:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Generative software that evolves images/textures/patterns

LICENSE=	GPLv2

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT4=	corelib gui xml moc_build qmake_build
USE_PYTHON=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"
MAKE_JOBS_UNSAFE=	yes

MAN1=		evolvotron.1 evolvotron_mutate.1 evolvotron_render.1

PORTDOCS=	NEWS README TODO USAGE evolvotron.html

INSTALLS_ICONS=	yes
ICON_SIZES=	32x32 48x48 64x64 72x72 96x96 128x128

DESKTOP_ENTRIES="Evolvotron" "Interactive image generator" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Graphics;2DGraphics;" true

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

.if ${CXX:T:M*clang*} || ${OSVERSION} >= 1000024
.for i in libevolvotron libfunction
CXXFLAGS+=	-include ${WRKSRC}/${i}/${i}_precompiled.h \
		-I${WRKSRC}/${i}
.endfor
.else
QMAKEFLAGS+=	CONFIG+=precompile_header
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|/bin/sh|' \
		${WRKSRC}/configure ${WRKSRC}/VERSION
	@${REINPLACE_CMD} -e \
		'/^CONFIG/s|precompile_header|| ; \
		 /DEFINES/s|_LINUX|_BSD|' ${WRKSRC}/common.pro

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX} \
		VERSION_NUMBER="${PORTVERSION}" main.pro

do-install:
.for i in evolvotron evolvotron_mutate evolvotron_render
	${INSTALL_PROGRAM} ${WRKSRC}/${i}/${i} ${PREFIX}/bin/
.endfor
.for lib in libevolvotron libfunction
	${INSTALL_DATA} ${WRKSRC}/${lib}/${lib}.a ${PREFIX}/lib/
.endfor

post-install:
.for s in ${ICON_SIZES}
	${MKDIR} ${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png ${PREFIX}/share/pixmaps/
	(cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/)

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
