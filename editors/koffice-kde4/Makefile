# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}-${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl2

_NO_KDE_PATCHUP=yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	DO_NOT_COMPILE=kontour	# KDE calls it "badly broken"

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

pre-configure:
	cd ${WRKSRC} && ${GMAKE} -f Makefile.cvs

.include <bsd.port.mk>
