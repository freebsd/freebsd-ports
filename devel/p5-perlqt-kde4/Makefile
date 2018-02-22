# $FreeBSD$

PORTNAME=	perlqt
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde kde-kde4 perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Perl bindings for Qt

LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2 \
		libqwt.so:x11-toolkits/qwt5

USES=		cmake:outsource kde:4 perl5 tar:xz
USE_KDE=	smokeqt qimageblitz
USE_QT4=	corelib dbus gui network xml \
		qmake_build moc_build uic_build rcc_build
USE_CXXSTD=	gnu++98

# Respect PREFIX
CMAKE_ARGS+=	-DCUSTOM_PERL_SITE_ARCH_DIR=${PREFIX}/${SITE_ARCH_REL}
# Fix build PREFIX != KDE_PREFIX
CMAKE_ARGS+=	-DSmoke_DIR=${KDE_PREFIX}/lib/cmake/smoke

SUB_FILES=	perl-kdebindings-env.sh pkg-message
SUB_LIST+=	PERL5LIBDIR="${PREFIX}/${SITE_ARCH_REL}:\
				${PREFIX}/${SITE_PERL_REL}"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/perl-kdebindings-env.sh ${STAGEDIR}${PREFIX}/env

.include <bsd.port.mk>
