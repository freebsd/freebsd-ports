# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jumpnbump
PORTVERSION=	1.60
CATEGORIES=	games
MASTER_SITES=	https://gitlab.com/LibreGames/jumpnbump/repository/${PORTVERSION}/archive.tar.bz2?dummy=/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Play cute bunnies jumping on each other's heads

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/menu/jumpnbump_menu.py.pre
USE_SDL=	sdl2 mixer2 net2

WRKSRC=		${WRKDIR}/${DISTNAME}-3b37e6f8951419bfce4601cda0ed500622d5bedf
PORTDOCS=	AUTHORS ChangeLog README.md

OPTIONS_DEFINE=	LAUNCHER DOCS NLS
OPTIONS_DEFAULT=LAUNCHER
OPTIONS_SUB=	yes

LAUNCHER_DESC=		Install pygtk launcher
LAUNCHER_USES=		python:2.7,run
LAUNCHER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk2>0:x11-toolkits/py-gtk2@${PY_FLAVOR}

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
