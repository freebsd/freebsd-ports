# New ports collection makefile for:	KDE SDK
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdesdk
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2

USE_KDEBASE_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

# Doesn't compile due to C++-unsafe header sys/wait.h.
# XXX: Need to figure out when this actually happens.
.if ${OSVERSION} > 500000
WITHOUT_CERVISIA=	yes
.endif # ${OSVERSION} > 500000

.if defined(WITHOUT_CERVISIA)
DO_NOT_COMPILE+=cervisia
.else
PLIST_APPEND+=	plist.cervisia
.include "${FILESDIR}/manpages.mk"
.endif # defined(WITHOUT_CERVISIA)

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

.include <bsd.port.post.mk>
