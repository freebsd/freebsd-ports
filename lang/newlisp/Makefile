# New ports collection makefile for:	newlisp
# Date created:		2006-09-13
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	newlisp
PORTVERSION=	10.2.8
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	http://www.newlisp.org/downloads/
#MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	stas@FreeBSD.org
COMMENT=	LISP like scripting language

HAS_CONFIGURE=	yes
ALL_TARGET=	default

MAN1=	newlisp.1 newlispdoc.1

REINPLACE_ARGS=	-i ""

MODULES=	cgi crypto ftp infix odbc pop3 postscript smtp stat unix \
		xmlrpc-client zlib

DOCS=		CHANGES CodePatterns.html ExpressionEvaluation.html \
		MemoryManagement.html newLISP-${PORTVERSION}-Release.html \
		manual_frame.html newLISPdoc.html \
		newlisp_index.html newlisp_manual.html \

OPTIONS=	GMP	"Enable GMP math library support" off \
		MYSQL5	"Build with mysql 5.0.x support" off \
		MYSQL51	"Build with mysql 5.1.x support" off \
		SQLITE	"Build with sqlite support" off \
		GUISERV "Install GUI server (in JAVA)" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
CFLAGS+=	-DNEWLISP64
.endif

.if defined(WITH_GMP)
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
MODULES+=	gmp
PLIST_SUB+=	GMP=""
.else
PLIST_SUB+=	GMP="@comment "
.endif

.if defined(WITH_MYSQL5)
USE_MYSQL=yes
WITH_MYSQL_VER=	50
MODULES+=	mysql
PLIST_SUB+=	MYSQL5=""
.else
PLIST_SUB+=	MYSQL5="@comment "
.endif

.if defined(WITH_MYSQL51)
USE_MYSQL=yes
WITH_MYSQL_VER=	51
MODULES+=	mysql
PLIST_SUB+=	MYSQL51=""
.else
PLIST_SUB+=	MYSQL51="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=3
MODULES+=	sqlite3
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if defined(WITH_GUISERV)
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newlisp ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/util/newlispdoc ${PREFIX}/bin/

	${MKDIR} ${DATADIR}/util/
	${INSTALL_DATA} ${WRKSRC}/util/syntax.cgi \
			${WRKSRC}/util/newlisp.vim \
			${WRKSRC}/util/link.lsp \
			${WRKSRC}/util/httpd-conf.lsp \
			${DATADIR}/util/

	${MKDIR} ${DATADIR}/modules/
	${INSTALL_DATA} ${MODULES:S,^,${WRKSRC}/modules/,:S,$,.lsp,} \
		${DATADIR}/modules/

	${INSTALL_MAN} ${WRKSRC}/doc/newlisp.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/newlispdoc.1 ${PREFIX}/man/man1/

.if defined(WITH_GUISERV)
	${MKDIR} ${DATADIR}/guiserver
	@(cd ${WRKSRC}/guiserver/ && ${COPYTREE_SHARE} \*.lsp \
		${DATADIR}/guiserver/ \
		"! -name guiserver.lsp ! -name newlisp-edit.lsp")
	${INSTALL_DATA} ${WRKSRC}/guiserver/guiserver.jar ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/guiserver/guiserver.lsp ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/guiserver/newlisp-edit.lsp \
		${PREFIX}/bin/newlisp-edit
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${MKDIR} ${EXAMPLESDIR}/

	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}/

	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/

. if defined(WITH_GUISERV)
	${MKDIR} ${DOCSDIR}/guiserver
	${INSTALL_DATA} ${WRKSRC}/guiserver/index.html \
			${WRKSRC}/guiserver/guiserver.lsp.html \
			${DOCSDIR}/guiserver/
. endif
.endif

.include <bsd.port.post.mk>
