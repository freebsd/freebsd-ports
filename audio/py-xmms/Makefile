# New ports collection makefile for:	py-xmms
# Date created:		19 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	xmms
PORTVERSION=	1.03
CATEGORIES=	audio python
MASTER_SITES=	http://www.via.ecp.fr/~flo/2002/PyXMMS/dist/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyxmms-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${XMMS_CONFIG}:${PORTSDIR}/audio/xmms
LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GLIB=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}
XMMS_CONFIG?=	${X11BASE}/bin/xmms-config
MAKE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" XMMS_CONFIG="${XMMS_CONFIG}"

.include <bsd.port.mk>
