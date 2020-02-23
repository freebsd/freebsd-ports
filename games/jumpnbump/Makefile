# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jumpnbump
PORTVERSION=	1.61
CATEGORIES=	games
MASTER_SITES=	https://gitlab.com/LibreGames/jumpnbump/repository/${PORTVERSION}/archive.tar.bz2?dummy=/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Play cute bunnies jumping on each other's heads #'

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		compiler:c11 gettext-tools gmake sdl shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/menu/jumpnbump_menu.py.pre
USE_SDL=	sdl2 mixer2 net2
ALL_TARGET=	all
INSTALL_TARGET=	install

WRKSRC=		${WRKDIR}/${DISTNAME}-7a0a7ab7491680338bb13058adafdfaac03a1f6d
PORTDOCS=	AUTHORS ChangeLog README.md

OPTIONS_DEFINE=	LAUNCHER DOCS NLS
OPTIONS_DEFAULT=LAUNCHER
OPTIONS_SUB=	yes

LAUNCHER_DESC=		Install pygtk launcher
LAUNCHER_USES=		python:2.7,run
LAUNCHER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>0:devel/py-gobject3@${PY_FLAVOR}
LAUNCHER_ALL_TARGET=	jnbmenu
LAUNCHER_INSTALL_TARGET=jnbmenuinstall

post-install:
.for f in jnbpack gobpack jnbunpack jumpnbump
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
