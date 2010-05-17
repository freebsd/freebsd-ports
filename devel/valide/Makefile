# New ports collection makefile for:	valide
# Date created:		2008-08-05
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	valide
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	http://${PORTNAME}.googlecode.com/files/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	An IDE for the Vala programming language

LIB_DEPENDS=	gdl-1:${PORTSDIR}/x11-toolkits/gdl
BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
RUN_DEPENDS=	${BUILD_DEPENDS}

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20 gtksourceview2
USE_LDCONFIG=	yes
USE_PYTHON=	yes

MAN1=		ctags-vala.1 valide.1

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON} ./waf --prefix="${PREFIX}" configure

do-build:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON} ./waf install

.include <bsd.port.mk>
