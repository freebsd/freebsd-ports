PORTNAME=	git-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	devel science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal interface for some git commands
WWW=		https://github.com/ArthurSonzogni/git-tui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libftxui-screen.so:devel/ftxui \
		libsubprocess.so:devel/subprocess

USES=		cmake:testing compiler:c++17-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ArthurSonzogni

PLIST_FILES=	bin/git-tui

.include <bsd.port.mk>
