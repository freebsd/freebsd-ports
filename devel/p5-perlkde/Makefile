# $FreeBSD$

PORTNAME=	perlkde
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde perl5
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Perl bindings for KDE

USE_KDE4=	perlqt smokekde automoc4
USE_QT4=	network opengl sql svg xml \
		qmake_build moc_build uic_build rcc_build
USES=		cmake:outsource compiler:c++11-lib perl5 tar:xz

# Respect PREFIX
CMAKE_ARGS+=	-DCUSTOM_PERL_SITE_ARCH_DIR=${PREFIX}/${SITE_ARCH_REL}

# Fix build PREFIX != KDE4_PREFIX
CMAKE_ARGS+=	-DSmoke_DIR=${KDE4_PREFIX}/lib/cmake/smoke \
		-DPerlQt_DIR=${KDE4_PREFIX}/share/perlqt/cmake \
		-DOkular_DIR=${KDE4_PREFIX}/lib/cmake/Okular

OPTIONS_DEFINE=	ATTICA
ATTICA_DESC=	Bindings for libattica (may crash build)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATTICA}
.if exists(${KDE4_PREFIX}/lib/libsmokekdecore.so) && \
	!exists(${KDE4_PREFIX}/lib/libsmokeattica.so)
IGNORE=	requires devel/smokekde built with ATTICA option
.endif
PLIST_SUB+=	ATTICA=""
.else
CMAKE_ARGS+=	-DWITH_LibAttica:BOOL=FALSE
PLIST_SUB+=	ATTICA="@comment "
.endif

.include <bsd.port.mk>
