# $FreeBSD$

PORTNAME=	golly
PORTVERSION=	3.3
DISTVERSIONSUFFIX=	-src
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Conway's Game of Life and other cellular automata

LICENSE=	GPLv2+

USES=		autoreconf compiler:c++11-lib gl localbase xorg
USE_GL=		gl glu
USE_WX=		3.0+

GNU_CONFIGURE=	yes
# Pretend objdump is available even if it is not e.g. on aarch64.
# The Python shared library name is already looked up via
# distutils.sysconfig.get_config_var("LDLIBRARY") which is unlikely
# to fail; objdump is never actually used.
CONFIGURE_ARGS=	ac_cv_prog_OBJDUMP=/usr/bin/false \
		--with-wx-config=${WX_CONFIG:T}

DESKTOP_ENTRIES=	"Golly" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/golly.xpm" \
			"${PREFIX}/bin/golly" \
			"Education;" \
			""

WRKSRC_SUBDIR=	gui-wx/configure
PATCH_WRKSRC=	${WRKSRC}/../..

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/../icons/appicon.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/golly.xpm

.include <bsd.port.mk>
