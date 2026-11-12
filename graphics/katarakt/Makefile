PORTNAME=	katarakt
PORTVERSION=	0.3
CATEGORIES=	graphics

MAINTAINER=	kurt@kmk-computers.de
COMMENT=	Simple PDF viewer uses as much available screen space as possible
WWW=		https://gitlab.cs.fau.de/Qui_Sum/katarakt

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libpoppler-qt6.so:graphics/poppler-qt6

USES=		gl pkgconfig qmake qt:6
USE_QT=		base
USE_GL=		gl

USE_GITLAB=	yes
GL_SITE=	https://gitlab.cs.fau.de
GL_ACCOUNT=	Qui_Sum
GL_TAGNAME=	v0.3

PLIST_FILES=	bin/katarakt \
		share/man/man1/katarakt.1.gz

post-build:
	cd ${WRKSRC} && ${MAKE} doc

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/katarakt.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
