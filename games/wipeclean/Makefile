# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	wipeclean
PORTVERSION=	1.1.0
CATEGORIES=	games
MASTER_SITES=	https://registry.npmjs.org/wipeclean/-/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	CLI tool to wipe away your error messages in style

LICENSE=	ISCL

USES=		nodejs:run tar:tgz
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/wipeclean

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/package/index.js \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
