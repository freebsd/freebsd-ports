PORTNAME=	buildsystem
PORTVERSION=	1.9
CATEGORIES=	devel
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
PKGNAMEPREFIX=	netsurf-

MAINTAINER=	nc@FreeBSD.org
COMMENT=	NetSurf project build system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USES=		gmake perl5 shebangfix
MAKE_ENV=	COMPONENT_TYPE="lib-shared"
SHEBANG_FILES=	testtools/testrunner.pl
NO_ARCH=	yes

.include <bsd.port.mk>
