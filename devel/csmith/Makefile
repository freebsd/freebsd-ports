PORTNAME=	csmith
DISTVERSIONPREFIX=	csmith-
DISTVERSION=	2.3.0-79
DISTVERSIONSUFFIX=	-g0ec6f1b
CATEGORIES=	devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Generates random C programs that conform to the C99 standard

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake libtool localbase perl5 shebangfix
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	csmith-project
USE_LDCONFIG=	yes
USE_PERL5=	run

SHEBANG_FILES=	scripts/compiler_test.pl scripts/launchn.pl
CXXFLAGS+=	-Wno-enum-constexpr-conversion
PLIST_SUB=	PKGNAME="${PKGNAME}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
