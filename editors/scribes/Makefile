# New ports collection makefile for:	scribes
# Date created:				24 November 2006
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scribes
PORTVERSION=	0.3.3.3
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/Stable%20Branch/${PORTNAME}-${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Slick yet powerful text editor for GNOME

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pygnomedesktop pygnomeextras gnomeprefix
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	scribes.schemas
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

.include <bsd.port.mk>
