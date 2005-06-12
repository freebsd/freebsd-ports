# New ports collection makefile for:	menueditor
# Date created:				22 March 2005
# Whom:					FreeBSD GNOME Team
#
# $FreeBSD$
#

PORTNAME=	smeg
PORTVERSION=	0.7.5
CATEGORIES=	deskutils
MASTER_SITES=	http://dev.realistanew.com/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An editor for the freedesktop.org menu specification

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg

USE_GNOME=	pygtk2
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|libdir, glob|'share/${PORTNAME}', glob|g ; \
		s|, 'lib/|, 'share/|g ; s|/usr/share|${X11BASE}/share|g" \
			${WRKSRC}/setup.py ${WRKSRC}/bin/${PORTNAME} \
			${WRKSRC}/lib/${PORTNAME}/MenuHandler.py \
			${WRKSRC}/lib/${PORTNAME}/DialogHandler.py

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
