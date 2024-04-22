PORTNAME=	par2cmdline
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	archivers

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Tools for using Parity v2 Archive files
WWW=		https://github.com/Parchive/par2cmdline

LICENSE=	GPLv2

USES=		autoreconf compiler:c++11-lang
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

USE_GITHUB=	yes
GH_ACCOUNT=	Parchive

PORTDOCS=	README
CONFLICTS=	par2cmdline-turbo

PLIST_FILES=	bin/par2 bin/par2create bin/par2repair bin/par2verify \
	share/man/man1/par2.1.gz

OPTIONS_DEFINE=	DOCS

TEST_TARGET=	check

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# ld: error: undefined symbol: __atomic_load
# See: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=230888
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
