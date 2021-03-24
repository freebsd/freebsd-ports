# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wyrmsun
PORTVERSION=	4.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Strategy game based on history, mythology and fiction

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

DEPRECATED=	Uses EOL Python 2.7 via games/wyrmgus
EXPIRATION_DATE=2021-06-23

RUN_DEPENDS=	wyrmgus:games/wyrmgus

USE_GITHUB=	yes
GH_ACCOUNT=	Andrettin
GH_PROJECT=	Wyrmsun

USES=		cmake gnome
INSTALL_TARGET=	install
INSTALLS_ICONS=	yes
NO_ARCH=	yes

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
