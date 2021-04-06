# Created by: Jeremy Norris <ishmael27@home.com>

PORTNAME=	scrot
DISTVERSION=	1.5
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SCReenshOT - command line screen capture utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libgiblib.so:graphics/giblib \
		libImlib2.so:graphics/imlib2

USE_GITHUB=	yes
GH_ACCOUNT=	resurrecting-open-source-projects

USES=		autoreconf xorg
USE_CSTD=	c99
GNU_CONFIGURE=	yes
USE_XORG=	x11 xfixes xcomposite

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
