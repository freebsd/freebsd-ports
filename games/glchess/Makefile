# New ports collection makefile for:	glchess
# Date created:				Wed Jul 18 08:35:56 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	glchess
PORTVERSION=	0.9.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D OpenGL based chess game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes

post-patch:
.for file in src/scene/builtin_models.py src/scene/new_models.py \
	src/scene/opengl.py src/ui/gtkui/dialogs.py src/ui/gtkui/gtkui.py
	@${REINPLACE_CMD} -e \
		's|/usr/share/games/glchess|${DATADIR}|g' ${WRKSRC}/${file}
.endfor

do-configure:
	@${ECHO_CMD} -n > ${WRKSRC}/glchess
	@${ECHO_CMD} '#!/bin/sh' >> ${WRKSRC}/glchess
	@${ECHO_CMD} 'exec ${PYTHON_CMD} ${DATADIR}/glchess.py' >> ${WRKSRC}/glchess

do-build:
.for lang in de en en_AU en_NZ en_US
	cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt ${lang}.po -o ${lang}.mo
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/glchess ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.py ${DATADIR}
	@${MKDIR} ${DATADIR}/chess
	${INSTALL_DATA} ${WRKSRC}/src/chess/*.py ${DATADIR}/chess
	@${MKDIR} ${DATADIR}/scene
	${INSTALL_DATA} ${WRKSRC}/src/scene/*.py ${DATADIR}/scene
	@${MKDIR} ${DATADIR}/ui
	${INSTALL_DATA} ${WRKSRC}/src/ui/*.py ${DATADIR}/ui
	@${MKDIR} ${DATADIR}/ui/gtkui
	${INSTALL_DATA} ${WRKSRC}/src/ui/gtkui/*.py ${DATADIR}/ui/gtkui
	@${MKDIR} ${DATADIR}/gui
	${INSTALL_DATA} ${WRKSRC}/src/ui/gtkui/*.glade ${DATADIR}/gui
	@${MKDIR} ${DATADIR}/textures
	${INSTALL_DATA} ${WRKSRC}/textures/*.* ${DATADIR}/textures
.for lang in de en en_AU en_NZ en_US
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/glchess.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
