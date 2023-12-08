PORTNAME=	winetricks
PORTVERSION=	20230903
PORTREVISION=	1
CATEGORIES=	emulators

MAINTAINER=	Alexander88207@protonmail.com
COMMENT=	Easy way to work around problems in Wine
WWW=		https://wiki.winehq.org/Winetricks

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Wine only runs on x86 architecture

RUN_DEPENDS=	cabextract:archivers/cabextract

USES=		perl5
USE_PERL5=	run

USE_GITHUB=	yes
GH_ACCOUNT=	Winetricks
GH_TAGNAME=	29e1006

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/winetricks \
		man/man1/winetricks.1.gz

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11

X11_RUN_DEPENDS=	xdg-open:devel/xdg-utils \
			zenity:x11/zenity

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/winetricks ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/winetricks.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
