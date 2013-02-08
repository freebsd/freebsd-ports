# $FreeBSD$

PORTNAME=	perlqt
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde perl5
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Perl bindings for Qt

LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2 \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5

USE_XZ=	yes
USE_PERL5=	yes
USE_KDE4=	kdehier kdeprefix smokeqt qimageblitz
USE_QT4=	qmake_build moc_build uic_build rcc_build
USE_CMAKE=	yes

MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

# Respect PREFIX
CMAKE_ARGS+=	-DCUSTOM_PERL_SITE_ARCH_DIR=${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}
# Fix build PREFIX != KDE4_PREFIX
CMAKE_ARGS+=	-DSmoke_DIR=${KDE4_PREFIX}/lib/cmake/smoke

SUB_FILES=	perl-kdebindings-env.sh pkg-message
SUB_LIST+=	PERL5LIBDIR="${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}:\
				${PREFIX}/${SITE_PERL_REL}"

post-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/perl-kdebindings-env.sh ${PREFIX}/env
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
