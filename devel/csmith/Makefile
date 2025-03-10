PORTNAME=	csmith
PORTVERSION=	2.3.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/csmith/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates random C programs that conform to the C99 standard
WWW=		https://embed.cs.utah.edu/csmith/

LICENSE=	BSD2CLAUSE

USES=		gmake libtool localbase perl5 shebangfix
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
USE_PERL5=	run

SHEBANG_FILES=	scripts/compiler_test.pl scripts/launchn.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}

INSTALL_TARGET=	install-strip

PLIST_SUB=	PKGNAME="${PKGNAME}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CPPFLAGS+=	-Wno-error=enum-constexpr-conversion
.endif

.include <bsd.port.mk>
