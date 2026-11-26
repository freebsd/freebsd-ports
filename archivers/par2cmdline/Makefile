PORTNAME=	par2cmdline
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Tools for using Parity v2 Archive files
WWW=		https://github.com/Parchive/par2cmdline

LICENSE=	GPLv2

USES=		cmake:testing compiler:c++14-lang

USE_GITHUB=	yes
GH_ACCOUNT=	Parchive

PORTDOCS=	README.md
CONFLICTS=	par2cmdline-turbo

OPTIONS_DEFINE=	DOCS

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
