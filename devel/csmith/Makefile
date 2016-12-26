# $FreeBSD$

PORTNAME=	csmith
PORTVERSION=	2.2.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/csmith/

MAINTAINER=	mokhi64@gmail.com
COMMENT=	Generates random C programs that conform to the C99 standard

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir=${DOCSDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		gmake libtool perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	scripts/compiler_test.pl scripts/launchn.pl scripts/test_csmith.pl
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

PLIST_SUB=	PKGNAME="${PKGNAME}"

.include <bsd.port.mk>
