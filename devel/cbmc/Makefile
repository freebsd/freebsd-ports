PORTNAME=	cbmc
PORTVERSION=	5.95.1
DISTVERSIONPREFIX=	cbmc-
CATEGORIES=	devel
MASTER_SITES=	DEBIAN/pool/main/m/minisat2:minisat
DISTFILES=	minisat2_2.2.1.orig.tar.gz:minisat

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Bounded Model Checker for C and C++ programs
WWW=		https://github.com/diffblue/cbmc

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
RUN_DEPENDS=	${LOCALBASE}/bin/cvc5:math/cvc5 \
		${LOCALBASE}/bin/z3:math/z3

USES=		gmake bison python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	diffblue
SHEBANG_FILES=	${WRKSRC}/scripts/ls_parse.py
WRKSRC_minisat=	${WRKDIR}/minisat2-2.2.1

post-patch:
	@${REINPLACE_CMD} -e 's|.*git describe --tags.*|GIT_INFO = ${PORTNAME}-${PORTVERSION}|' \
		${WRKSRC}/src/util/Makefile
post-extract:
	@${MV} ${WRKSRC_minisat} ${WRKSRC}/minisat-2.2.1

do-build:
	@${MKDIR} ${STAGEDIR}
	cd ${WRKSRC} && ${GMAKE} -C src -j${MAKE_JOBS_NUMBER}

do-install:
.  for x in cbmc crangler goto-analyzer goto-cc goto-diff goto-instrument \
	goto-inspect goto-harness goto-synthesizer symtab2gb
	${INSTALL_PROGRAM} ${WRKSRC}/src/${x}/${x} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/man/${x}.1 ${STAGEDIR}${PREFIX}/share/man/man1/
.  endfor
	${LN} -sf goto-cc ${STAGEDIR}${PREFIX}/bin/goto-gcc
	${LN} -sf goto-cc ${STAGEDIR}${PREFIX}/bin/goto-ld
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/ls_parse.py ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
