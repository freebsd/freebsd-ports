PORTNAME=	scrot
DISTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SCReenshOT - command line screen capture utility
WWW=		https://github.com/resurrecting-open-source-projects/scrot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		autoreconf pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	resurrecting-open-source-projects
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_XORG=	x11 xext xfixes xcomposite xinerama

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
