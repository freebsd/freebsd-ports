# New ports collection makefile for:	glchess
# Date created:				Wed Jul 18 08:35:56 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	glchess
PORTVERSION=	0.9.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D OpenGL based chess game

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext

USE_X_PREFIX=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	ChangeLog README TODO

post-patch:
.for file in glchess ui/gtkui/gtkui.py
	@${REINPLACE_CMD} -e \
		's|^python |${PYTHON_CMD} |g ; \
		 s|/usr/share/games/glchess|${DATADIR}|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/glchess ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${DATADIR}
	@${MKDIR} ${DATADIR}/gui
	${INSTALL_DATA} ${WRKSRC}/ui/gtkui/*.glade ${DATADIR}/gui
	@${MKDIR} ${DATADIR}/ui
	${INSTALL_DATA} ${WRKSRC}/ui/*.py ${DATADIR}/ui
	@${MKDIR} ${DATADIR}/ui/gtkui
	${INSTALL_DATA} ${WRKSRC}/ui/gtkui/*.py ${DATADIR}/ui/gtkui
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
