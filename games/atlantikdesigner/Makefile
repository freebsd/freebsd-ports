# New ports collection makefile for:	atlantikdesigner
# Date created:				11 Febrary 2004
# Whom:					Michael Nottebrock <lofi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${ATLANTIKDESIGNER_PORTNAME}
PORTVERSION=	${ATLANTIKDESIGNER_PORTVERSION}
PORTREVISION=	${ATLANTIKDESIGNER_PORTREVISION}
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Editor for Atlantik

LIB_DEPENDS=	atlantic:${PORTSDIR}/games/kdegames3

KDE_SPLIT=	${ATLANTIKDESIGNER_PORTNAME:S/${KDE_SPLIT_DIST}-//}
KDE_DOC_SPLIT=	# none
USE_KDELIBS_VER=3

USE_BZIP2=	yes
PREFIX=		${KDE_PREFIX}
USE_AUTOTOOLS=  libtool:22
USE_GMAKE=	yes

USE_LDCONFIG=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib/kde3

PLIST_SUB+=	KDE_VER="${KDE_VERSION}"

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include "${.CURDIR}/../../misc/kdeaddons3/Makefile.split"

.include <bsd.port.mk>
