# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fossology
PORTVERSION=	3.6.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-nomos-standalone

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Standalone Nomos license scanner from fossology project

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libjson-c.so:devel/json-c

USE_GITHUB=	yes

USES=		gnome gmake gettext pkgconfig
USE_GNOME=	glib20

BUILD_WRKSRC=	${WRKSRC}/src/nomos/agent
MAKEFILE=	Makefile.sa
MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	nomossa

PLIST_FILES=	bin/nomossa

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nomos/agent/nomossa ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
