# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arx-libertatis
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://cloud.github.com/downloads/arx/ArxLibertatis/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform port of Arx Fatalis

LICENSE=	GPLv3

LIB_DEPENDS=	IL:${PORTSDIR}/graphics/devil \
		GLEW:${PORTSDIR}/graphics/glew \
		freetype:${PORTSDIR}/print/freetype2 \
		boost_program_options:${PORTSDIR}/devel/boost-libs

USE_XZ=		yes
USE_OPENAL=	yes
USE_SDL=	sdl
USE_GL=		gl glu
USE_CMAKE=	yes
CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR="man" -DDATA_DIR=arx
MAKE_JOBS_SAFE=	yes

SUB_FILES=	pkg-message

MAN1=		arxsavetool.1 arxunpak.1
MAN6=		arx.6

PORTDOCS=	AUTHORS CHANGELOG README.md

OPTIONS=	CRASHREPORTER "Build crash reporter (requires Qt4)" off

.include <bsd.port.options.mk>

.if defined(WITH_CRASHREPORTER)
USE_QT4=	corelib gui network rcc_build moc_build uic_build qmake_build
CMAKE_ARGS+=	-DBUILD_CRASHREPORTER=ON
PLIST_SUB+=	CRASHREPORTER=""
.else
CMAKE_ARGS+=	-DBUILD_CRASHREPORTER=OFF
PLIST_SUB+=	CRASHREPORTER="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
