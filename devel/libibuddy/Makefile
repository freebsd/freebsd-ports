PORTNAME=	libibuddy
PORTVERSION=	0.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	C loadable library and CLI tool to control an i-buddy device
WWW=		https://www.osorio.me/projects/dev/libibbudy/

LICENSE=	BSD2CLAUSE

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	rosorio
USE_LDCONFIG=	yes

PLIST_FILES=	bin/ibuddy_test \
		bin/ibuddycmd \
		include/ibuddy.h \
		lib/libibuddy.so

.include <bsd.port.mk>
