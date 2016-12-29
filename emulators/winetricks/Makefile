# Created by: Nikolai Lifanov <lifanov@mail.lifanov.com>
# $FreeBSD$

PORTNAME=	winetricks
PORTVERSION=	20161228
CATEGORIES=	emulators

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Easy way to work around problems in Wine

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/src/COPYING

.if !defined(WITHOUT_X11)
RUN_DEPENDS=	zenity>0:x11/zenity
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	Winetricks

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/winetricks man/man1/winetricks.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/winetricks ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/winetricks.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
