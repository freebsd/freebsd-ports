# $FreeBSD$

PORTNAME=	ghostwriter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.4
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Distraction-free Markdown editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell

USES=		compiler:c++11-lang desktop-file-utils pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	wereturtle
USE_QT=		concurrent core gui network printsupport svg webkit widgets \
		buildtools_build linguisttools_build
LDFLAGS+=	-Wl,--as-needed # cf. PR 224488

post-patch:
	@${REINPLACE_CMD} 's,share/man/,man/,' ${WRKSRC}/ghostwriter.pro

.include <bsd.port.mk>
