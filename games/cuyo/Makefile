# Created by: Matthew Gibson <mdg583@hotmail.com>
# $FreeBSD$

PORTNAME=	cuyo
PORTVERSION=	2.1.0
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice, innovative, challenging Tetris-like game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome iconv localbase:ldflags sdl xorg
USE_SDL=	mixer image
USE_XORG=	x11 xau xdmcp
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

# Do not use older versions
PORTSCOUT=	limit:[0-9]\.[0-9]\.

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_BUILD_DEPENDS=	gsed:textproc/gsed
NLS_USES=		gettext perl5
NLS_USE=		perl5=build
NLS_LDFLAGS=		-lintl

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} NEWS README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
