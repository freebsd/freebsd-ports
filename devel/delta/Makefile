PORTNAME=	delta
DISTVERSIONPREFIX=	release-
DISTVERSION=	2020-06-22
CATEGORIES=	devel

MAINTAINER=	se@FreeBSD.org
COMMENT=	Heuristically minimizes interesting files
WWW=		https://github.com/dsw/delta/

LICENSE=	BSD2CLAUSE

USES=		gmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dsw
USE_PERL5=	run
SHEBANG_FILES=	delta multidelta test0_delta/hello.test test*_multidelta/testit

TEST_TARGET=	check

CONFLICTS_INSTALL=	git-delta

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/delta ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/multidelta ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/topformflat ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
