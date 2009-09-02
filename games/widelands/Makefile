# Ports collection makefile for:        widelands
# Date created:                         8 April 2007
# Whom:                                 Bartosz Fabianowski <freebsd@chillt.de>
#
# $FreeBSD$
#

PORTNAME=	widelands
DISTVERSION=	build13
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/build-13
DISTNAME=	${PORTNAME:C/^w/W/}-${DISTVERSION:C/^b/B/}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		boost_thread.4:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_PYTHON_BUILD=2.4+
USE_SDL=	sdl mixer image net ttf gfx
USE_GCC=	4.2+

PLIST_FILES=	bin/widelands

WRKSRC=		${WRKDIR}/widelands-${DISTVERSION:C/build/b/}

USE_SCONS=	yes
SCONS_ARGS=	install_prefix=${PREFIX} bindir=bin datadir=share/widelands \
		localedir=share/widelands/locale build=release \
		sdlconfig=${SDL_CONFIG}
MAKE_JOBS_SAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/prefer_localdata/ s|True|False|' \
		${WRKSRC}/worlds/SConscript
	@${REINPLACE_CMD} -e '/ifndef/ s|__APPLE__|__FreeBSD__|' \
		${WRKSRC}/src/backtrace.cc
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/utils/buildlocale.py
	@${REINPLACE_CMD} -e 's|revstring=.*|return "${DISTVERSION}-FreeBSD"|' \
		${WRKSRC}/build/scons-tools/detect_revision.py

post-install:
	@${FIND} ${DATADIR} -type f | \
		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
