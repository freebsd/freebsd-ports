# New ports collection makefile for:	koffice
# Date created:				Sun May 14 2000 16:33:15
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koffice
PORTVERSION=	1.1.1
PORTEPOCH=	1
CATEGORIES=	editors kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/src
DISTNAME=	${PORTNAME}-${PORTVERSION}-kde3
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_PYTHON=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif
USE_GMAKE=	yes

pre-configure:
	cd ${WRKSRC} && ${GMAKE} -f Makefile.cvs

.include <bsd.port.mk>
