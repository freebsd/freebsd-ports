# New ports collection makefile for:	kdebindings4-perl-perlkde
# Date created:		2012-02-24
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	perlkde
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde perl5
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	p5-kdebindings-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Perl bindings for KDE

USE_XZ=	yes
USE_PERL5=	yes
# Build fails with system gcc
USE_GCC=	4.6+
USE_KDE4=	kdehier kdeprefix perlqt smokekde automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build
USE_CMAKE=	yes

MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

# Respect PREFIX
CMAKE_ARGS+=	-DCUSTOM_PERL_SITE_ARCH_DIR=${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}

# Fix build PREFIX != KDE4_PREFIX
CMAKE_ARGS+=	-DSmoke_DIR=${KDE4_PREFIX}/lib/cmake/smoke \
		-DPerlQt_DIR=${KDE4_PREFIX}/share/perlqt/cmake \
		-DOkular_DIR=${KDE4_PREFIX}/lib/cmake/Okular

OPTIONS=	ATTICA "Bindings for libattica" off

.include <bsd.port.pre.mk>

.ifdef(WITH_ATTICA)
.if exists(${KDE4_PREFIX}/lib/libsmokekdecore.so) && \
	!exists(${KDE4_PREFIX}/lib/libsmokeattica.so)
IGNORE=	requires devel/kdebindings4-smoke-smokekde built with ATTICA option
.endif
PLIST_SUB+=	ATTICA=""
.else
CMAKE_ARGS+=	-DWITH_LibAttica:BOOL=FALSE
PLIST_SUB+=	ATTICA="@comment "
.endif

.include <bsd.port.post.mk>
