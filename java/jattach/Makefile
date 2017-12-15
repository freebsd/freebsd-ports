# $FreeBSD$

PORTNAME=	jattach
DISTVERSION=	g20170928
CATEGORIES=	java devel

MAINTAINER=	mizhka@gmail.com
COMMENT=	JVM dynamic attach utility

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	gmake

USE_GITHUB=	yes
GH_ACCOUNT=	apangin
GH_TAGNAME=	ccc2f05

PLIST_FILES=	bin/jattach

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/jattach ${STAGEDIR}${PREFIX}/bin/jattach

.include <bsd.port.mk>
