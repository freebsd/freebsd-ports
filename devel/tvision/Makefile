PORTNAME=	tvision
PORTVERSION=	g20250515
CATEGORIES=	devel

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Modern port of Turbo Vision 2.0, a TUI framework
WWW=		https://github.com/magiblot/tvision

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing localbase ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	magiblot
GH_PROJECT=	tvision
GH_TAGNAME=	df6424f

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_TESTING_ON=	TV_BUILD_TESTS # several tests fail, see https://github.com/magiblot/tvision/issues/176

.include <bsd.port.mk>
