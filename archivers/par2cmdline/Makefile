PORTNAME=	par2cmdline
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Tools for using Parity v2 Archive files

LICENSE=	GPLv2

USES=		autoreconf compiler:c++11-lang
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Parchive

PORTDOCS=	README
CONFLICTS=	par2cmdline-tbb

PLIST_FILES=	bin/par2 bin/par2create bin/par2repair bin/par2verify man/man1/par2.1.gz

OPTIONS_DEFINE=	DOCS

TEST_TARGET=	check

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# ld: error: undefined symbol: __atomic_load
# See: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=230888
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
