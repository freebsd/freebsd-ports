# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	wipeclean
PORTVERSION=	g20220222
CATEGORIES=	games

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	CLI tool to wipe away your error messages in style

LICENSE=	ISCL

USES=		nodejs:run
USE_GITHUB=	yes
GH_ACCOUNT=	JeanJouliaCode
GH_PROJECT=	wipeClean
GH_TAGNAME=	858b089
NO_BUILD=	yes

PLIST_FILES=	bin/wipeclean

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/index.js \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
