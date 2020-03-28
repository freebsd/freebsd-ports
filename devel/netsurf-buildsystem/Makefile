# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	buildsystem
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
PKGNAMEPREFIX=	netsurf-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetSurf project buildsystem

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

USES=		gmake perl5 shebangfix
MAKE_ENV=	COMPONENT_TYPE="lib-shared"
SHEBANG_FILES=	testtools/testrunner.pl
NO_ARCH=	yes

.include <bsd.port.mk>
