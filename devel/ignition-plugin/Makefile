# $FreeBSD$

PORTNAME=	ignition-plugin
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for registering plugins and dynamically loading them

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ignition-cmake==2:devel/ignition-cmake

USES=		cmake:outsource compiler:c++17-lang
USE_LDCONFIG=	yes

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-plugin
BB_COMMIT=	6bf2bf09570f

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_SUB+=	PLUGIN_IGN_VER=plugin${DISTVERSION:R:R}

.include <bsd.port.mk>
