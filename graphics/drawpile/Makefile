PORTNAME=	Drawpile
DISTVERSION=	2.2.2
PORTREVISION=	3
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collaborative drawing program
WWW=		https://drawpile.net

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libsodium.so:security/libsodium \
		libwebpmux.so:graphics/webp

USES=		cargo cmake compiler:c++17-lang desktop-file-utils kde:5 pkgconfig qt:5 shared-mime-info
USE_QT=		core gui multimedia network opengl sql svg widgets xml websockets \
		buildtools:build linguisttools:build qmake:build
USE_KDE=	archive dnssd ecm:build

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_CRATES=	aho-corasick-1.0.5 \
		anyhow-1.0.75 \
		memchr-2.6.1 \
		regex-1.9.4 \
		regex-automata-0.3.7 \
		regex-syntax-0.7.5 \
		xflags-0.3.1 \
		xflags-macros-0.3.1

BINARY_ALIAS=	lconvert=${QT_BINDIR}/lconvert

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:tl}
PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTSCOUT=	limit:^\d+\. # prevent tags like 'continuous'

.include <bsd.port.pre.mk>

#.if ${ARCH} == armv7
#BROKEN_FreeBSD_15=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276269
#.endif

.include <bsd.port.post.mk>
