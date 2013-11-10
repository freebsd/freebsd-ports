# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	itools
PORTVERSION=	0.62.9
CATEGORIES=	devel python
MASTER_SITES=	http://download.hforge.org/itools/0.62/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python library Provides Wide Range Of Capabilities

LICENSE=	GPLv3

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}reportlab2>=2.3:${PORTSDIR}/print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}gobject>=2.16.1:${PORTSDIR}/devel/py-gobject \
		${PYTHON_PKGNAMEPREFIX}pygit2>=0:${PORTSDIR}/devel/py-pygit2
RUN_DEPENDS+=	${BUILD_DEPENDS}
LIB_DEPENDS=	glib:${PORTSDIR}/devel/glib20 \
		soup:${PORTSDIR}/devel/libsoup

LDFLAGS+=	-L${LOCALBASE}/lib
USES=		pkgconfig
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
