# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	xmms
PORTVERSION=	2.07
CATEGORIES=	audio python
MASTER_SITES=	http://people.via.ecp.fr/~flo/projects/PyXMMS/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyxmms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS Remote Control Library for Python

BUILD_DEPENDS=	${XMMS_CONFIG}:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

DEPRECATED=	Depends on deprecated on forbidden xmms
EXPIRATION_DATE=	2014-04-08
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_BZIP2=	yes
USE_GNOME=	glib12
XMMS_CONFIG?=	${LOCALBASE}/bin/xmms-config
MAKE_ENV=	XMMS_CONFIG="${XMMS_CONFIG}"

.include <bsd.port.mk>
