# $FreeBSD$

PORTNAME=	ghostwriter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.1
CATEGORIES=	editors

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Distraction-free Markdown editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		compiler:c++11-lang desktop-file-utils pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	wereturtle
USE_QT=		core gui svg webchannel webengine widgets buildtools_build \
		linguisttools_build

# cf. PR 224488
LDFLAGS+=	-Wl,--as-needed

.include <bsd.port.mk>
