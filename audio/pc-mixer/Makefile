# $FreeBSD$

PORTNAME=	pc-mixer
PORTVERSION=	20171212
CATEGORIES=	audio

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	QT5 based audio mixer for FreeBSD

LICENSE=	BSD2CLAUSE

WRKSRC_SUBDIR=	src-qt5
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

MAKE_JOBS_UNSAFE=yes
USES=		qmake shebangfix tar:xz
USE_LDCONFIG=	yes
USE_QT5=	core gui network svg linguist \
		buildtools x11extras widgets multimedia
USE_GL+=	gl

WRKSRC_SUBDIR=	src-qt5

QMAKE_ARGS=	CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pc-mixer
GH_TAGNAME=	ac1d74cc261337998526d091123c28d4ae85277e

PLIST_FILES=	bin/pc-mixer \
		share/applications/pc-mixer.desktop

.include <bsd.port.mk>
