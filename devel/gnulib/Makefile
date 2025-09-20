PORTNAME=	gnulib
PORTVERSION=	20140202
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://erislabs.net/ianb/projects/gnulib/
DISTNAME=	${PORTNAME}-${PORTVERSION}-stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU portability library
WWW=		https://www.gnu.org/software/gnulib/

LICENSE=	GPLv2+ GPLv3+ LGPL20+ LGPL3+ PD
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:print/texinfo

USES=		cpe gmake perl5 shebangfix
SHEBANG_FILES=	check-module lib/uniname/gen-uninames.lisp
SHEBANG_LANG=	perl clisp
clisp_OLD_CMD=	/usr/local/bin/clisp
clisp_CMD=	${LOCALBASE}/bin/clisp
CPE_VENDOR=	gnu

NO_ARCH=	yes

BUILD_WRKSRC=	${WRKSRC}/doc
ALL_TARGET=	info html
PLIST_FILES=	bin/check-module bin/gnulib-tool
INFO=		${PORTNAME}
PORTDOCS=	gnulib.html
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,date -u.*,stat -f %Sa -t "@set UPDATED %F %T" `${LS} -t $$^ | ${SED} 1q` > $$@,' \
		-e 's: makeinfo$$: ${LOCALBASE}/bin/makeinfo:' \
		${WRKSRC}/doc/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${PREFIX}/${INFO_PATH}
.for p in check-module gnulib-tool
	${INSTALL_SCRIPT} ${WRKSRC}/${p} ${STAGEDIR}${DATADIR}/
	${LN} -s ../${DATADIR_REL}/${p} ${STAGEDIR}${PREFIX}/bin/
.endfor
	${TAR} -cf - -C ${WRKSRC} build-aux config doc lib m4 modules \
		tests top | ${TAR} -xof - -C ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/gnulib.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
