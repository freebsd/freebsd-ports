# New ports collection makefile for:	py-xmms
# Date created:		19 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	2.02
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://people.via.ecp.fr/~flo/2002/PyXMMS/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyxmms-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	XMMS Remote Control Library for Python

BUILD_DEPENDS=	${XMMS_CONFIG}:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_BZIP2=	yes
USE_GNOME=	glib12
XMMS_CONFIG?=	${X11BASE}/bin/xmms-config
MAKE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" XMMS_CONFIG="${XMMS_CONFIG}"

.include <bsd.port.mk>
