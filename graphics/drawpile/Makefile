PORTNAME=	Drawpile
DISTVERSION=	2.1.20
PORTREVISION=	4
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collaborative drawing program
WWW=		https://drawpile.net

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake:devel/kf5-extra-cmake-modules
LIB_DEPENDS=	libgif.so:graphics/giflib \
		libmicrohttpd.so:www/libmicrohttpd \
		libminiupnpc.so:net/miniupnpc \
		libsodium.so:security/libsodium \
		libvpx.so:multimedia/libvpx

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 pkgconfig qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}
USE_QT=		core gui multimedia network sql svg widgets buildtools:build linguisttools:build qmake:build
USE_KDE=	archive dnssd

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTSCOUT=	limit:^\d+\. # prevent tags like 'continuous'

.include <bsd.port.pre.mk>

.if ${ARCH} == armv7
BROKEN_FreeBSD_15=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276269
.endif

.include <bsd.port.post.mk>
