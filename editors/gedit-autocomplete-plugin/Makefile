# Ports collection makefile for:	gedit-autocomplete-plugin
# Date created:				2005-10-10
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	autocomplete-plugin
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://usuarios.lycos.es/acisif/gedit/autocomplete/
PKGNAMEPREFIX=	gedit-

MAINTAINER=	andreas@syndrom23.de
COMMENT=	A simple autocompletion plugin for gedit

BUILD_DEPENDS=	gedit:${PORTSDIR}/editors/gedit
RUN_DEPENDS=	gedit:${PORTSDIR}/editors/gedit

GEDIT_VERSION=	2.14

BROKEN=		Not compatible with gedit versions >= 2.14

USE_X_PREFIX=	yes
MAKEFILE=	makefile
MAKE_ARGS=	GEDIT_VERSION=gedit-${GEDIT_VERSION}

PLIST_FILES=	lib/gedit-2/plugins/autocomplete.gedit-plugin \
		lib/gedit-2/plugins/libautocomplete.so

.include <bsd.port.mk>
