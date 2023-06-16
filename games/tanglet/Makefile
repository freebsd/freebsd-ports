PORTNAME=	tanglet
PORTVERSION=	1.6.4
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/tanglet/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Single player word finding game based on Boggle
WWW=		https://gottcode.org/tanglet/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang desktop-file-utils gl \
		qt:6 shared-mime-info tar:bzip2
USE_GL=		opengl
USE_QT=		base tools:build

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
