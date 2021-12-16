PORTNAME=	jattach
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0
CATEGORIES=	java devel

MAINTAINER=	mizhka@FreeBSD.org
COMMENT=	JVM dynamic attach utility

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	gmake

USE_GITHUB=	yes
GH_ACCOUNT=	apangin

PLIST_FILES=	bin/jattach

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/jattach ${STAGEDIR}${PREFIX}/bin/jattach

.include <bsd.port.mk>
