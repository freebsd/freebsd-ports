PORTNAME=	sedsed
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Python script that masters SED scripts
WWW=		https://aurelio.net/projects/sedsed/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	aureliojargas

SHEBANG_FILES=	sedsed.py

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/sedsed

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin/sedsed

.include <bsd.port.mk>
