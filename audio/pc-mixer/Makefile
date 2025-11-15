PORTNAME=	pc-mixer
PORTVERSION=	20171212
PORTREVISION=	4
CATEGORIES=	audio

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	Qt5 based audio mixer for FreeBSD
WWW=		https://github.com/trueos/pc-mixer

LICENSE=	BSD2CLAUSE

DEPRECATED=	Abandoned upstream and depends on deprecated QT5
EXPIRATION_DATE=2025-12-31

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

MAKE_JOBS_UNSAFE=yes
USES=		compiler:c++11-lang gl qmake qt:5 shebangfix tar:xz
USE_LDCONFIG=	yes
USE_QT=		core gui network svg linguist \
		buildtools x11extras widgets multimedia
USE_GL+=	gl

WRKSRC_SUBDIR=	src-qt5

QMAKE_ARGS=	CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_TAGNAME=	ac1d74cc261337998526d091123c28d4ae85277e

PLIST_FILES=	bin/pc-mixer \
		share/applications/pc-mixer.desktop

.include <bsd.port.mk>
