# New ports collection makefile for:	tnl
# Date created:		05 Feb 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	tnl
PORTVERSION=	071111
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://tnlgame.net/downloads/tnl/${PORTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	TnL-source-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME:S/source/data/}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Futuristic action flight simulator and realtime strategy game

BUILD_DEPENDS=	${LOCALBASE}/lib/libiovmall.so:${PORTSDIR}/lang/io
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		CEGUIBase.3:${PORTSDIR}/graphics/cegui \
		png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GCC=	4.2+
USE_GL=		glew
USE_OPENAL=	al alut

CONFIGURE_ARGS=	--with-io-cflags="-I${LOCALBASE}/include/io" \
		--with-io-libs="-L${LOCALBASE}/lib -liovmall"

WRKDATADIR=	${WRKDIR}/TnL-data/share/tnl

SUB_FILES=	tnl

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|getenv|getEnvironmentVariable|' \
		${WRKDATADIR}/scripts/Settings.io

post-install:
	${MKDIR} ${DATADIR}
	cd ${WRKDATADIR} && ${COPYTREE_SHARE} . ${DATADIR}

	${INSTALL_SCRIPT} ${WRKDIR}/tnl ${PREFIX}/bin

.include <bsd.port.mk>
