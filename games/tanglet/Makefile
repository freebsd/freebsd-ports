PORTNAME=	tanglet
PORTVERSION=	1.6.9
CATEGORIES=	games
MASTER_SITES=	https://gottcode.org/tanglet/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Single player word finding game based on Boggle
WWW=		https://gottcode.org/tanglet/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools gl \
		qt:6 shared-mime-info tar:bzip2
USE_GL=		opengl
USE_QT=		base tools:build

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
