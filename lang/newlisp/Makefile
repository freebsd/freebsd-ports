# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	newlisp
PORTVERSION=	10.5.3
CATEGORIES=	lang
MASTER_SITES=	http://www.newlisp.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	LISP like scripting language

LIB_DEPENDS=	ffi:${PORTSDIR}/devel/libffi

CONFLICTS=	newlisp-devel-[0-9]*

HAS_CONFIGURE=	yes
ALL_TARGET=	default

MAN1=		newlisp.1 newlispdoc.1

REINPLACE_ARGS=	-i ""

MODULES=	canvas cgi crypto ftp getopts infix macro odbc pop3 \
		postscript smtp smtpx stat unix xmlrpc-client zlib

DOCS=		CHANGES CodePatterns.html ExpressionEvaluation.html \
		MemoryManagement.html newLISP-${PORTVERSION}-Release.html \
		manual_frame.html newLISPdoc.html \
		newlisp_index.html newlisp_manual.html \

OPTIONS_DEFINE=	GMP GSL MYSQL PGSQL SQLITE GUISERV
GSL_DESC=	GSL (GNU Scientific Library)
GUISERV_DESC=	Install GUI server (in Java)

.include <bsd.port.options.mk>

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
CFLAGS+=	-DNEWLISP64
.endif

.if ${PORT_OPTIONS:MGMP}
LIB_DEPENDS+=	gmp:${PORTSDIR}/math/gmp
MODULES+=	gmp
PLIST_SUB+=	GMP=""
.else
PLIST_SUB+=	GMP="@comment "
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	gsl:${PORTSDIR}/math/gsl
MODULES+=	gsl
PLIST_SUB+=	GSL=""
.else
PLIST_SUB+=	GSL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
MODULES+=	mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
MODULES+=	postgres
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	3
MODULES+=	sqlite3
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MGUISERV}
PLIST_SUB+=	GUISERV=""
.else
PLIST_SUB+=	GUISERV="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s,install -m 644, \$${BSD_INSTALL_DATA},g" \
		-e "s,install -m 755, \$${BSD_INSTALL_SCRIPT},g" \
		-e "s,^(datadir=).*,\1${PREFIX}/share,g" \
		-e "s,^(bindir=).*,\1${PREFIX}/bin,g" \
		${WRKSRC}/Makefile

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
		"s,/usr/local/lib/libgmp.so,${LOCALBASE}/lib/libgmp.so," \
		${WRKSRC}/modules/gmp.lsp
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
	${INSTALL_PROGRAM} ${WRKSRC}/newlisp ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/newlispdoc ${PREFIX}/bin

	@${MKDIR} ${DATADIR}/util
	${INSTALL_DATA} ${WRKSRC}/util/syntax.cgi \
			${WRKSRC}/util/newlisp.vim \
			${WRKSRC}/util/link.lsp \
			${WRKSRC}/util/httpd-conf.lsp \
			${WRKSRC}/util/newlisp.jsf \
			${DATADIR}/util

	@${MKDIR} ${DATADIR}/modules
	${INSTALL_DATA} ${MODULES:S,^,${WRKSRC}/modules/,:S,$,.lsp,} \
		${DATADIR}/modules

	${INSTALL_MAN} ${WRKSRC}/doc/newlisp.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/newlispdoc.1 ${PREFIX}/man/man1

.if ${PORT_OPTIONS:MGUISERV}
	@${MKDIR} ${DATADIR}/guiserver
	@(cd ${WRKSRC}/guiserver/ && ${COPYTREE_SHARE} \*.lsp \
		${DATADIR}/guiserver/ \
		"! -name guiserver.lsp ! -name newlisp-edit.lsp")
	${INSTALL_DATA} ${WRKSRC}/guiserver/guiserver.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/guiserver/guiserver.lsp ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/guiserver/newlisp-edit.lsp \
		${PREFIX}/bin/newlisp-edit
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.if ${PORT_OPTIONS:MGUISERV}
	@${MKDIR} ${DOCSDIR}/guiserver
	${INSTALL_DATA} ${WRKSRC}/guiserver/index.html \
		${WRKSRC}/guiserver/guiserver.lsp.html \
		${DOCSDIR}/guiserver
.endif
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
