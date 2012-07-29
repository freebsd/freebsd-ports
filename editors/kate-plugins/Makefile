# New ports collection makefile for:	kdeaddons-kate-plugins
# Date created:				11 Feb 2004 19:51:40
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${KATEPLUGINS_PORTNAME}
PORTVERSION=	${KATEPLUGINS_PORTVERSION}
PORTREVISION=	${KATEPLUGINS_PORTREVISION}
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional plugins and features for kate

KDE_SPLIT=	kate
KDE_DOC_SPLIT=	kate-plugins
USE_KDEBASE_VER=3
USE_KDELIBS_VER=3

USE_BZIP2=	yes
PREFIX=		${KDE_PREFIX}
USE_AUTOTOOLS=  libtool
USE_GMAKE=	yes

USE_LDCONFIG=	yes

PLIST_SUB+=	KDE_VER="${KDE_VERSION}"

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include "${.CURDIR}/../../misc/kdeaddons3/Makefile.split"
.include <bsd.port.mk>
