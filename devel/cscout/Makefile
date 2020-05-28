# Created by: netchild@FreeBSD.org
# $FreeBSD$

PORTNAME=	cscout
PORTVERSION=	3.01
CATEGORIES=	devel

MAINTAINER=	dds@FreeBSD.org
COMMENT=	Source code analyzer and refactoring browser for C program collections

LICENSE=	GPLv3

BUILD_DEPENDS=	unzip:archivers/unzip
RUN_DEPENDS=	dot:graphics/graphviz

USES=		compiler:c++11-lang gmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dspinellis dspinellis:swill,btyacc
GH_PROJECT=	cscout swill:swill btyacc:btyacc
GH_TAGNAME=	bd7dfac fafde76:swill 4d0be15:btyacc
GH_SUBDIR=	swill:swill btyacc:btyacc
USE_PERL5=	run build
SHEBANG_FILES=	src/csmake.pl src/cswc.pl

# DOCS temporary disabled, need XML -> HTML conversion
OPTIONS_DEFINE=	EXAMPLES #DOCS
SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} -e 's|install -d \"|install -d \"${STAGEDIR}/|g' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e 's|install -Ds $$< \"|install -s $$< \"${STAGEDIR}/|g' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} -e 's|./dest-install.sh \"|./dest-install.sh \"${STAGEDIR}/|g' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/cscout.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/cswc.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/cscc.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/csmake.1 ${STAGEDIR}${PREFIX}/man/man1

#do-install-DOCS-on:
#	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
