# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	newlisp
PORTVERSION=	10.6.2
CATEGORIES=	lang
MASTER_SITES=	http://www.newlisp.org/downloads/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	LISP like scripting language

LICENSE=	GPLv3

LIB_DEPENDS=	libffi.so:devel/libffi

CONFLICTS=	newlisp-devel-[0-9]*

USES=		readline:port tar:tgz
OPTIONS_SUB=	yes

HAS_CONFIGURE=	yes
ALL_TARGET=	default

REINPLACE_ARGS=	-i ""

MODULES=	canvas cgi crypto ftp getopts infix odbc plot pop3 \
		postscript smtp smtpx stat unix xmlrpc-client zlib

DOCS=		CHANGES CodePatterns.html ExpressionEvaluation.html \
		MemoryManagement.html manual_frame.html \
		newLISP-${PORTVERSION}-Release.html newLISPdoc.html \
		newlisp-man.txt newlisp_index.html newlisp_manual.html \
		newlispdoc-man.txt

OPTIONS_DEFINE=	GSL MYSQL PGSQL SQLITE GUISERV DOCS EXAMPLES
GSL_DESC=	GSL (GNU Scientific Library)
GUISERV_DESC=	Install GUI server (in Java)

.include <bsd.port.options.mk>

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
CFLAGS+=	-DNEWLISP64
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	libgsl.so:math/gsl
MODULES+=	gsl
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
MODULES+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
MODULES+=	postgres
.endif

.if ${PORT_OPTIONS:MSQLITE}
USES+=		sqlite
MODULES+=	sqlite3
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,/usr/(local/)?bin/newlisp,${PREFIX}/bin/newlisp,g" \
		-e "s,/usr/(local/)?share/newlisp,${DATADIR},g" \
		-e "s,/usr/(local/)?lib/newlisp.so,${PREFIX}/lib/newlisp.so,g"\
		-e "s,/usr/bin,${PREFIX}/bin,g" \
		-e "s,/usr/local/bin/vi,/usr/bin/vi,g" \
		${WRKSRC}/examples/* \
		${WRKSRC}/doc/* \
		${WRKSRC}/guiserver/*.lsp \
		${WRKSRC}/modules/* \
		${WRKSRC}/newlisp.c

	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/mysql/lib/(libmysqlclient.)dylib,${LOCALBASE}/lib/mysql/\1so.${MYSQL${MYSQL_VER}_LIBVER}," \
		${WRKSRC}/modules/mysql.lsp
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/lib/(libsqlite)3.so,${LOCALBASE}/lib/\1${_SQLITE_VER}.so," \
		${WRKSRC}/modules/sqlite3.lsp
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/lib/libgsl.so,${LOCALBASE}/lib/libgsl.so," \
		${WRKSRC}/modules/gsl.lsp
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/lib/libpq.so.5.1,${LOCALBASE}/lib/libpq.so.5," \
		${WRKSRC}/modules/postgres.lsp
	@${REINPLACE_CMD} -E -e \
		"s,/usr/share/newlisp,${LOCALBASE}/share/newlisp," \
		${WRKSRC}/newlisp.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newlisp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/newlispdoc ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DATADIR}/util
	${INSTALL_DATA} ${WRKSRC}/util/syntax.cgi \
			${WRKSRC}/util/README.txt \
			${WRKSRC}/util/newlisp.jsf \
			${WRKSRC}/util/newlisp.vim \
			${WRKSRC}/util/standard.lsp \
			${STAGEDIR}${DATADIR}/util

	@${MKDIR} ${STAGEDIR}${DATADIR}/modules
	${INSTALL_DATA} ${MODULES:S,^,${WRKSRC}/modules/,:S,$,.lsp,} \
		${STAGEDIR}${DATADIR}/modules

	${INSTALL_MAN} ${WRKSRC}/doc/newlisp.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/newlispdoc.1 ${STAGEDIR}${PREFIX}/man/man1

.if ${PORT_OPTIONS:MGUISERV}
	@${MKDIR} ${STAGEDIR}${DATADIR}/guiserver
	@(cd ${WRKSRC}/guiserver/ && ${COPYTREE_SHARE} \*.lsp \
		${STAGEDIR}${DATADIR}/guiserver/ \
		"! -name guiserver.lsp ! -name newlisp-edit.lsp")
	${INSTALL_DATA} ${WRKSRC}/guiserver/guiserver.jar ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/guiserver/guiserver.lsp ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/guiserver/newlisp-edit.lsp \
		${STAGEDIR}${PREFIX}/bin/newlisp-edit
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MGUISERV}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/guiserver
	${INSTALL_DATA} ${WRKSRC}/guiserver/index.html \
		${WRKSRC}/guiserver/guiserver.lsp.html \
		${STAGEDIR}${DOCSDIR}/guiserver
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
