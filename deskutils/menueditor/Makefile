# New ports collection makefile for:	menueditor
# Date created:				22 March 2005
# Whom:					FreeBSD GNOME Team
#
# $FreeBSD$
#

PORTNAME=	menueditor
PORTVERSION=	0.4.3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://dev.realistanew.com/menu-editor/ \
		http://dev.realistanew.com/menu-editor/old/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A simple menu editor for GNOME 2.10

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_GNOME=	pygtk2
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|\[(libdir,|\[('share/gnome/menu-editor',|g ; \
		s|, 'lib/|, 'share/gnome/|g ; \
		s|'share/pixmaps|'share/gnome/pixmaps|g ; \
		s|'share/applications|'share/gnome/applications|g ; \
		s|/usr/share|${X11BASE}/share/gnome|g ; \
		s|/etc|${X11BASE}/etc|g" \
			${WRKSRC}/setup.py ${WRKSRC}/bin/menu-editor \
			${WRKSRC}/lib/menu-editor/menu_handler.py

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/share/gnome/menu-editor

.include <bsd.port.mk>
