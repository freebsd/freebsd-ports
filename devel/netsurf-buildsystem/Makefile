# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	buildsystem
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
PKGNAMEPREFIX=	netsurf-

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	NetSurf project buildsystem

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

MAKE_ENV+=	COMPONENT_TYPE=lib-shared \

USES=	gmake shebangfix perl5

SHEBANG_LANG=	perl
perl_CMD=	${SETENV} perl
SHEBANG_FILES=	testtools/testrunner.pl

.include <bsd.port.mk>
