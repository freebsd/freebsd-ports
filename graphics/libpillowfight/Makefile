# $FreeBSD$

PORTNAME=	libpillowfight
DISTVERSION=	0.2.4
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library containing various image processing algorithms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake
TEST_DEPENDS=	gmake:devel/gmake \
		tox:devel/py-tox@${PY_FLAVOR}

USES=		cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org/World
GL_ACCOUNT=	OpenPaperwork
GL_COMMIT=	3a7ebba75f4c060ac1707900bd8891e8d200b1c6
USE_LDCONFIG=	yes

TEST_USES=	python

PLIST_FILES=	include/pillowfight/pillowfight.h \
		include/pillowfight/util.h \
		lib/libpillowfight.so

pre-configure:
	@cd ${WRKSRC} && ${GMAKE} version

do-test: # many tests fail due to various reasons: https://gitlab.gnome.org/World/OpenPaperwork/libpillowfight/issues/18#note_279228
	@cd ${WRKSRC} && ${GMAKE} test

.include <bsd.port.mk>
