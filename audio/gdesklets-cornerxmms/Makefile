# New ports collection makefile for:	gdesklets-cornerxmms
# Date created:				22 December 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#

PORTNAME=	cornerxmms
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	http://gdesklets.gnomedesktop.org/files/
PKGNAMEPREFIX=	gdesklets-
DISTNAME=	CornerXMMS-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	A fancy desklet that allows you to control XMMS from the desktop

DEPRECATED=		dead project and not fetchable any more
EXPIRATION_DATE=	2006-10-12

RUN_DEPENDS=	gdesklets:${PORTSDIR}/deskutils/gdesklets \
		${PYTHON_SITELIBDIR}/xmms/__init__.py:${PORTSDIR}/audio/py-xmms

USE_PYTHON=	yes
USE_XLIB=	yes

NAME=		CornerXMMS
DATADIR=	${PREFIX}/share/gnome
WRKSRC=		${WRKDIR}/${NAME}-${PORTVERSION}

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${DATADIR}/gdesklets/Controls/KIconAnim
	@${MKDIR} ${DATADIR}/gdesklets/Controls/KXmms
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}
	@${MKDIR} ${DATADIR}/gdesklets/Displays/${NAME}/gfx
	@${INSTALL_DATA} ${WRKSRC}/Controls/KIconAnim/* ${DATADIR}/gdesklets/Controls/KIconAnim/
	@${INSTALL_DATA} ${WRKSRC}/Controls/KXmms/* ${DATADIR}/gdesklets/Controls/KXmms/
	@${INSTALL_DATA} ${WRKSRC}/Displays/${NAME}/*.display ${DATADIR}/gdesklets/Displays/${NAME}/
	@${INSTALL_DATA} ${WRKSRC}/Displays/${NAME}/gfx/*.png ${DATADIR}/gdesklets/Displays/${NAME}/gfx/

.include <bsd.port.mk>
