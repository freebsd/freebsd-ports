PORTNAME=	connectagram
PORTVERSION=	1.3.4
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/connectagram/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Word unscrambling game
WWW=		https://gottcode.org/connectagram/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang gl qt:6 tar:bzip2
USE_GL=		opengl
USE_QT=		base tools:build

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
