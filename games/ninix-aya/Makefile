# New ports collection makefile for:	ninix-aya
# Date created:				6 Dec 2003
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME= 	ninix-aya
PORTVERSION=	3.0.2
PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ninix-aya/10956
DISTNAME=	ninix-aya-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Ninix-aya is a compatible with desktop mascot program "Ukagaka"

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip \
		lha:${PORTSDIR}/archivers/lha \
		${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

PLIST_SUB=	LOCALBASE=${LOCALBASE}

USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/ninix-aya-${PORTVERSION}

.include <bsd.port.mk>
