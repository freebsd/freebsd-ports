PORTNAME=	ecrire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	editors enlightenment
DIST_SUBDIR=	enlightenment

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	EFL (Enlightenment) graphical text editor
WWW=		https://github.com/Obsidian-StudiosInc/ecrire

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libefl.so:devel/efl

USES=		cmake desktop-file-utils pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Obsidian-StudiosInc

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_BOOL=	ENABLE_NLS

.include <bsd.port.mk>
