PORTNAME=	firebird-emu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
CATEGORIES=	emulators

MAINTAINER=	nsonack@herrhotzenplotz.de
COMMENT=	Emulator of the ARM-based TI-Nspire calculators
WWW=		https://github.com/nspire-emus/firebird/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libGL.so:graphics/libglvnd

USES=		compiler:c++17-lang desktop-file-utils gl qmake qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	nspire-emus
GH_PROJECT=	firebird
GH_TUPLE=	jacobly0:gif-h:8cb648f:firebird/core/gif-h

USE_QT=		core declarative gui network widgets buildtools:build
USE_GL+=	gl

PLIST_FILES=	bin/firebird-emu \
		bin/firebird-send \
		share/applications/org.firebird-emus.firebird-emu.desktop \
		share/icons/hicolor/512x512/apps/org.firebird-emus.firebird-emu.png

.include <bsd.port.mk>
