# New ports collection makefile for:	KDE SDK
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdesdk
PORTVERSION=	2.1.1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	demon@FreeBSD.org

USE_KDELIBS_VER=2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		cvs2pack.1 cvschanged.1 cvsversion.1 noncvslist.1 kde-build.1

.include <bsd.port.mk>
