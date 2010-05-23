# New ports collection makefile for:	py-xmms
# Date created:		19 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	2.02
PORTREVISION=	4
CATEGORIES=	audio python
MASTER_SITES=	http://people.via.ecp.fr/~flo/2002/PyXMMS/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyxmms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS Remote Control Library for Python

BUILD_DEPENDS=	${XMMS_CONFIG}:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	pyxmms
USE_BZIP2=	yes
USE_GNOME=	glib12
XMMS_CONFIG?=	${LOCALBASE}/bin/xmms-config
MAKE_ENV=	XMMS_CONFIG="${XMMS_CONFIG}"

.include <bsd.port.mk>
