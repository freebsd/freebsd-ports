PORTNAME=	andi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient estimation of evolutionary distances
WWW=		https://github.com/EvolBioInf/andi

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdivsufsort.so:math/libdivsufsort \
		libgsl.so:math/gsl

USES=		autoreconf gmake localbase pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	EvolBioInf

GNU_CONFIGURE=	yes

TEST_TARGET=	check-TESTS # No tests are run, see https://github.com/EvolBioInf/andi/issues/18

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

PLIST_FILES=	bin/andi \
		share/man/man1/andi.1.gz

.include <bsd.port.mk>
