# New ports collection makefile for:	KDE2 Graphics
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics
PORTVERSION=	2.1.1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

BUILD_DEPENDS=	dvips:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	dvips:${PORTSDIR}/print/teTeX

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
