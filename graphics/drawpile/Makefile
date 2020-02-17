# $FreeBSD$

PORTNAME=	Drawpile
DISTVERSION=	2.1.17
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collaborative drawing program

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libmicrohttpd.so:www/libmicrohttpd \
		libminiupnpc.so:net/miniupnpc \
		libsodium.so:security/libsodium \
		libvpx.so:multimedia/libvpx

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 pkgconfig qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}
USE_QT=		core gui multimedia network sql svg widgets buildtools_build linguisttools_build qmake_build
USE_KDE=	archive dnssd

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
