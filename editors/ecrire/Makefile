# $FreeBSD$

PORTNAME=	ecrire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.3
CATEGORIES=	editors enlightenment
DIST_SUBDIR=	enlightenment

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	EFL (Enlightenment) graphical text editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libefl.so:devel/efl

USES=		cmake desktop-file-utils pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Obsidian-StudiosInc

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_BOOL=	ENABLE_NLS

.include <bsd.port.mk>
