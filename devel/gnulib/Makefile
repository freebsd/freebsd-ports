PORTNAME=	gnulib
PORTVERSION=	20260127
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU portability library
WWW=		https://www.gnu.org/software/gnulib/

LICENSE=	GPLv2+ GPLv3+ LGPL20+ LGPL3+ PD
LICENSE_COMB=	multi

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/bin/makeinfo:print/texinfo

USES=		cpe gmake perl5 python shebangfix
SHEBANG_FILES=	build-aux/vcs-to-changelog.py \
		check-module \
		lib/uniname/gen-uninames.lisp
SHEBANG_LANG=	perl clisp
clisp_OLD_CMD=	/usr/local/bin/clisp
clisp_CMD=	${LOCALBASE}/bin/clisp
CPE_VENDOR=	gnu

USE_GITHUB=	yes
GH_ACCOUNT=	coreutils
GH_TAGNAME=	dc9ad4ec31fb09d247036f6a031e4ec6efbaa26c

NO_ARCH=	yes

ALL_TARGET=	all info html
TEST_TARGET=	check
PLIST_FILES=	bin/check-module \
		bin/gnulib-tool \
		${DOCSDIR}/gnulib.html \
		share/info/gnulib.info \
		${DATADIR}/.gnulib-tool.py
PORTDATA=	*
MAKE_JOBS_UNSAFE=yes

post-patch:
	${REINPLACE_CMD} -e 's|python3 -c|${PYTHON_CMD} -c|' \
		${WRKSRC}/gnulib-tool \
		${WRKSRC}/gnulib-tool.py
	${REINPLACE_CMD} -e 's|exec python3|exec ${PYTHON_CMD}|' \
		${WRKSRC}/gnulib-tool.py
	@${REINPLACE_CMD} -e 's,date -u.*,stat -f %Sa -t "@set UPDATED %F %T" `${LS} -t $$^ | ${SED} 1q` > $$@,' \
		-e 's: makeinfo$$: ${LOCALBASE}/bin/makeinfo:' \
		${WRKSRC}/doc/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} \
		${STAGEDIR}${PREFIX}/${INFO_PATH} \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/.gnulib-tool.py ${WRKSRC}/gnulib-tool.py \
		${STAGEDIR}${DATADIR}
.for p in check-module gnulib-tool
	${INSTALL_SCRIPT} ${WRKSRC}/${p} ${STAGEDIR}${DATADIR}/
	${LN} -s ../${DATADIR_REL}/${p} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${TAR} -cf - -C ${WRKSRC} build-aux config doc lib m4 modules pygnulib \
		tests top | ${TAR} -xof - -C ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
