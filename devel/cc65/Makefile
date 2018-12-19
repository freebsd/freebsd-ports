# Created by: Tim Vanderhoek <hoek@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cc65
PORTVERSION=	2.17
DISTVERSIONPREFIX=	V
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Cross-compiler for 6502-based systems

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake perl5 shebangfix
USE_PERL5=	build
USE_GITHUB=	yes

MAKE_JOBS_UNSAFE=	yes

SHEBANG_FILES=	util/ca65html

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		'/gcc/s|^CC|#CC| ; \
		/-O2/s|^CFLAGS|#CFLAGS|'

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
