PORTNAME=	opendungeons
PORTVERSION=	0.7.1
PORTREVISION=	8
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source game inspired by Dungeon Keeper
WWW=		https://opendungeons.github.io/

LICENSE=	CC-BY-3.0 CC-BY-SA-3.0 CC0-1.0 GPLv3 MIT OFL11
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-3.0=	${WRKSRC}/licenses/CC-BY-3.0.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/licenses/CC-BY-SA-3.0.txt
LICENSE_FILE_CC0-1.0=	${WRKSRC}/licenses/CC0.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/GPL-3.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/licenses/MIT.txt
LICENSE_FILE_OFL11=	${WRKSRC}/licenses/SIL-Open-Font-License.txt

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs \
		libOIS.so:devel/ois \
		libsfml-audio.so:devel/sfml \
		libCEGUIBase-0.so:graphics/cegui \
		libOgreMain.so:graphics/ogre3d19

BROKEN=		error: no template named 'conditional_t' in namespace 'std'
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=2023-02-14

USES=		cmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	OpenDungeons
GH_PROJECT=	OpenDungeons

CMAKE_ARGS=	-DOD_BIN_PATH:PATH=${PREFIX}/bin \
		-DOD_PLUGINS_CFG_PATH:PATH=${ETCDIR} \
		-DOD_ENABLE_WARNINGS:BOOL=FALSE \
		-DOD_TREAT_WARNINGS_AS_ERRORS:BOOL=FALSE

LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
