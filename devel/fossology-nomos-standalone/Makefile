# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fossology
PORTVERSION=	3.3.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-nomos-standalone

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Standalone Nomos license scanner from fossology project

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	gawk:lang/gawk

USE_GITHUB=	yes
GH_TAGNAME=	660fc06

USES=		gmake gettext pkgconfig
USE_GNOME=	glib20

BUILD_WRKSRC=	${WRKSRC}/src/nomos/agent
MAKEFILE=	Makefile.sa
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/nomossa

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nomos/agent/nomossa ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
