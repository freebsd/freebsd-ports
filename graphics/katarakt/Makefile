PORTNAME=	katarakt
PORTVERSION=	0.2
PORTREVISION=	33
CATEGORIES=	graphics

MAINTAINER=	kurt@kmk-computers.de
COMMENT=	Simple PDF viewer uses as much available screen space as possible
WWW=		https://gitlab.cs.fau.de/Qui_Sum/katarakt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5
USE_QT=		buildtools:build core gui xml dbus network widgets
USE_GL=		gl

USE_GITLAB=	yes
GL_SITE=	https://gitlab.cs.fau.de
GL_ACCOUNT=	Qui_Sum
GL_TAGNAME=	99735bc0b15b57d689b6c982d43b85ed1b40ef45

PLIST_FILES=	bin/katarakt \
		share/man/man1/katarakt.1.gz

post-build:
	cd ${WRKSRC} && ${MAKE} doc

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/katarakt.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
