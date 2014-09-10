# $FreeBSD$

PORTNAME=	perlqt
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde perl5
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Perl bindings for Qt

LIB_DEPENDS=	libqscintilla2.so:${PORTSDIR}/devel/qscintilla2 \
		libqwt.so:${PORTSDIR}/x11-toolkits/qwt5

USE_KDE4=	kdehier kdeprefix smokeqt qimageblitz
USE_QT4=	corelib dbus gui network xml \
		qmake_build moc_build uic_build rcc_build
USES=		cmake:outsource perl5 tar:xz

# Respect PREFIX
CMAKE_ARGS+=	-DCUSTOM_PERL_SITE_ARCH_DIR=${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}
# Fix build PREFIX != KDE4_PREFIX
CMAKE_ARGS+=	-DSmoke_DIR=${KDE4_PREFIX}/lib/cmake/smoke

SUB_FILES=	perl-kdebindings-env.sh pkg-message
SUB_LIST+=	PERL5LIBDIR="${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}:\
				${PREFIX}/${SITE_PERL_REL}"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/perl-kdebindings-env.sh ${STAGEDIR}${PREFIX}/env

.include <bsd.port.mk>
