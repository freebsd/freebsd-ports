# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	valide
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://launchpadlibrarian.net/68237064/

MAINTAINER=	romain@FreeBSD.org
COMMENT=	An IDE for the Vala programming language

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

LIB_DEPENDS=	gdl-1:${PORTSDIR}/x11-toolkits/gdl
BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN=		Doesn't build with vala 0.12+

INSTALLS_ICONS=	yes
USES=		gettext
USE_GNOME=	gtk20 gtksourceview2
USE_LDCONFIG=	yes
USE_PYTHON=	yes

MAN1=		ctags-vala.1 valide.1

NO_STAGE=	yes
do-configure:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON} ./waf --prefix="${PREFIX}" configure

do-build:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON} ./waf install

.include <bsd.port.mk>
