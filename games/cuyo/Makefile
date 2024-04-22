PORTNAME=	cuyo
PORTVERSION=	2.1.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice, innovative, challenging Tetris-like game
WWW=		https://www.karimmi.de/cuyo/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome iconv localbase:ldflags sdl xorg
USE_CXXSTD=	c++14
USE_SDL=	mixer image
USE_XORG=	x11 xau xdmcp

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

# Do not use older versions
PORTSCOUT=	limit:[0-9]\.[0-9]\.

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes

NLS_BUILD_DEPENDS=	gsed:textproc/gsed
NLS_USES=		gettext perl5
NLS_USE=		perl5=build
NLS_CONFIGURE_ENABLE=	nls
NLS_LDFLAGS=		-lintl

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} NEWS README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
