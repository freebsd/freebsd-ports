# $FreeBSD$

PORTNAME=	perlkde
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	7
CATEGORIES=	devel kde kde-kde4 perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Perl bindings for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake:outsource compiler:c++11-lib kde:4 perl5 qt:4 tar:xz
USE_KDE=	perlqt smokekde automoc4
USE_QT=		network opengl sql svg xml \
		qmake_build moc_build uic_build rcc_build

# Respect PREFIX
CMAKE_ARGS+=	-DCUSTOM_PERL_SITE_ARCH_DIR=${PREFIX}/${SITE_ARCH_REL}

# Fix build PREFIX != KDE_PREFIX
CMAKE_ARGS+=	-DSmoke_DIR=${KDE_PREFIX}/lib/cmake/smoke \
		-DPerlQt_DIR=${KDE_PREFIX}/share/perlqt/cmake \
		-DOkular_DIR=${KDE_PREFIX}/lib/cmake/Okular

OPTIONS_DEFINE=	ATTICA
ATTICA_DESC=	Bindings for libattica (may crash build)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATTICA}
.if exists(${KDE_PREFIX}/lib/libsmokekdecore.so) && \
	!exists(${KDE_PREFIX}/lib/libsmokeattica.so)
IGNORE=	requires devel/smokekde built with ATTICA option
.endif
PLIST_SUB+=	ATTICA=""
.else
CMAKE_ARGS+=	-DWITH_LibAttica:BOOL=FALSE
PLIST_SUB+=	ATTICA="@comment "
.endif

.include <bsd.port.mk>
