# $FreeBSD$

PORTNAME=	snorenotify
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Multi platform Qt notification framework

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL-3

USES=		cmake kde:5 qt:5
USE_KDE=	ecm
USE_QT=		core dbus gui network widgets buildtools_build qmake_build
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	KDE

.include <bsd.port.mk>
