# New ports collection makefile for:	KDE SDK
# Date created:				2 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdesdk
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db

USE_KDEBASE_VER=3
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_BZIP2=	yes
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

MAN1=		cvs2pack.1 cvsversion.1 noncvslist.1 kde-build.1

.include <bsd.port.mk>
