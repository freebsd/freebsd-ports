# New ports collection makefile for:	moleskine
# Date created:				14 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moleskine
PORTVERSION=	0.6.5
CATEGORIES=	editors python gnome
MASTER_SITES=	http://www.moleskine.f2s.com/files/
DISTNAME=	${PORTNAME:S/^m/M/}-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

RUN_DEPENDS=	${PYTHON_LIBDIR}/site-packages/_gnomemodule.so:${PORTSDIR}/x11-toolkits/py-gnome \
		${PYTHON_LIBDIR}/site-packages/_gtkscintillamodule.so:${PORTSDIR}/x11-toolkits/py-gtkscintilla

USE_X_PREFIX=	yes
USE_PYTHON=	yes

INST_DIR=	${PREFIX}/share/gnome/Moleskine
CONF_DIR=	${PREFIX}/etc/gnome/config/Moleskine

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${INST_DIR}/Moleskine
	${MKDIR} ${INST_DIR}/dialogs
	${MKDIR} ${INST_DIR}/images
	${MKDIR} ${CONF_DIR}
	${INSTALL_DATA} ${WRKSRC}/LanguageModes ${CONF_DIR}
	${INSTALL_DATA} ${WRKSRC}/Preferences ${CONF_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/moleskine ${INST_DIR}
	${LN} -sf ${INST_DIR}/moleskine ${PREFIX}/bin/moleskine
	${INSTALL_DATA} ${WRKSRC}/Moleskine/*.py ${WRKSRC}/Moleskine/*.pyc ${INST_DIR}/Moleskine
	${INSTALL_DATA} ${WRKSRC}/dialogs/*.glade ${INST_DIR}/dialogs
	${INSTALL_DATA} ${WRKSRC}/images/*.jpeg ${INST_DIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${INST_DIR}/images
	${INSTALL_DATA} ${WRKSRC}/moleskine.desktop ${PREFIX}/share/gnome/apps/Development
	${INSTALL_DATA} ${WRKSRC}/images/moleskine.png ${PREFIX}/share/gnome/pixmaps

.include <bsd.port.mk>
