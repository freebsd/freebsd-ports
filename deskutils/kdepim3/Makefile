# New ports collection makefile for:	KDE PIM
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdepim
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal Information Management tools for KDE

LIB_DEPENDS=	pisock:${PORTSDIR}/palm/pilot-link

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.include <bsd.port.post.mk>
