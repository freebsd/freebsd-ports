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
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

MAN1=		cvs2pack.1 cvsversion.1 noncvslist.1 kde-build.1

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.pre.mk>

# Doesn't compile due to C++-unsafe header sys/wait.h.
# XXX: Need to figure out when this actually happens.
.if ${OSVERSION} > 500000
CONFIGURE_ENV=	DO_NOT_COMPILE="cervisia"
PLIST_SUB+=	CERVISIA="@comment "
.else
PLIST_SUB+=	CERVISIA=""
.endif

.include <bsd.port.post.mk>
