# $FreeBSD$

PORTNAME=	winetricks
PORTVERSION=	20191224
CATEGORIES=	emulators

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Easy way to work around problems in Wine

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	cabextract:archivers/cabextract

USES=		perl5
USE_PERL5=	run

USE_GITHUB=	yes
GH_ACCOUNT=	Winetricks

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/winetricks man/man1/winetricks.1.gz

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11

X11_RUN_DEPENDS=	xdg-open:devel/xdg-utils \
			zenity:x11/zenity

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/winetricks ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/winetricks.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
