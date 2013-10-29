# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/accessibility/accerciser/Makefile,v 1.36 2010/04/27 21:38:19 kwm Exp $

PORTNAME=	accerciser
PORTVERSION=	1.12.1
PORTREVISION=	2
CATEGORIES=	accessibility gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Interactive Python accessibility explorer for GNOME

USE_BZIP2=	yes
USE_GNOME=	pygnomedesktop atspi intlhack
USE_PYTHON=	-2.7
USES=		display:configure gettext gmake pkgconfig
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	accerciser.schemas

.include <bsd.port.mk>
