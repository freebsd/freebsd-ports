PORTNAME=	libmpdclient
PORTVERSION=	2.23
CATEGORIES=	audio
MASTER_SITES=	https://www.musicpd.org/download/libmpdclient/2/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API library for interfacing MPD
WWW=		https://www.musicpd.org/libs/libmpdclient/ \
		https://github.com/MusicPlayerDaemon/libmpdclient

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSES/BSD-2-Clause.txt
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSES/BSD-3-Clause.txt

USES=		meson tar:xz

MESON_ARGS=	--default-library=both
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes
DOXYGEN_IMPLIES=DOCS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_MESON_TRUE=	documentation

.include <bsd.port.mk>
