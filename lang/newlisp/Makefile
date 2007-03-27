# New ports collection makefile for:	newlisp
# Date created:		2006-09-13
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	newlisp
PORTVERSION=	9.1.1
PORTREVISION=	0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	stas@FreeBSD.org
COMMENT=	LISP like scripting language

HAS_CONFIGURE=	yes
ALL_TARGET=	default

TK_VER=	8.5
MAN1=	newlisp.1

REINPLACE_ARGS=	-i ""

MODULES=	cgi ftp infix odbc pop3 postscript smtp stat unix \
		xmlrpc-client zlib

PORTDOCS=	CHANGES CodePatterns.html MemoryManagement.html \
		keywords.txt manual_frame.html newLISPdoc.html \
		newlisp_index.html newlisp_manual.html

OPTIONS=	TK	"Build with TK support" off \
		GMP	"Enable GMP math library support" off \
		MYSQL4	"Build with mysql4 support" off \
		MYSQL5	"Build with mysql5 support" off \
		SQLITE	"Build with sqlite support" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL4) && defined(WITH_MYSQL5)
IGNORE=	you should select only one MySQL version
.endif

.if defined(WITH_TK)
RUN_DEPENDS+=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${TK_VER:S,.,,g}
MAN1+=		newlisp-tk.1
PLIST_SUB+=	TK=""
.else
PLIST_SUB+=	TK="@comment "
.endif

.if defined(WITH_GMP)
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4
MODULES+=	gmp
PLIST_SUB+=	GMP=""
.else
PLIST_SUB+=	GMP="@comment "
.endif

.if defined(WITH_MYSQL4)
USE_MYSQL=yes
WITH_MYSQL_VER=	41
MODULES+=	mysql
PLIST_SUB+=	MYSQL4=""
.else
PLIST_SUB+=	MYSQL4="@comment "
.endif

.if defined(WITH_MYSQL5)
USE_MYSQL=yes
WITH_MYSQL_VER=	50
MODULES+=	mysql5
PLIST_SUB+=	MYSQL5=""
.else
PLIST_SUB+=	MYSQL5="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=3
MODULES+=	sqlite3
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s,install -m 644, \$${BSD_INSTALL_DATA},g" \
		-e "s,install -m 755, \$${BSD_INSTALL_SCRIPT},g" \
		-e "s,^(datadir=).*,\1${PREFIX}/share,g" \
		-e "s,^(mandir=).*,\1${PREFIX}/man,g" \
		-e "s,^(bindir=).*,\1${PREFIX}/bin,g" \
		${WRKSRC}/Makefile

	@${REINPLACE_CMD} -E \
		-e "s,/usr/bin/newlisp,${PREFIX}/bin/newlisp,g" \
		-e "s,/usr/share/newlisp,${DATADIR},g" \
		-e "s,/usr/lib/newlisp.so,${PREFIX}/lib/newlisp.so,g" \
		-e "s,exec wish,exec wish${TK_VER}," \
		-e "s,/usr/bin,${PREFIX}/bin,g" \
		${WRKSRC}/examples/* \
		${WRKSRC}/doc/* \
		${WRKSRC}/modules/* \
		${WRKSRC}/init.lsp.example \
		${WRKSRC}/newlisp.c \
		${WRKSRC}/newlisp-tk/newlisp-tk.tcl

	@${REINPLACE_CMD} -E -e \
		"s,/usr/lib/(libmysqlclient.so.)14,${LOCALBASE}/lib/mysql/\1${MYSQL${MYSQL_VER}_LIBVER}," \
		${WRKSRC}/modules/mysql.lsp
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/mysql/lib/(libmysqlclient.)dylib,${LOCALBASE}/lib/mysql/\1so.${MYSQL${MYSQL_VER}_LIBVER}," \
		${WRKSRC}/modules/mysql5.lsp
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/lib/(libsqlite)3.so,${LOCALBASE}/lib/\1${_SQLITE_VER}.so," \
		${WRKSRC}/modules/sqlite3.lsp
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/lib/libgmp.so,${LOCALBASE}/lib/libgmp.so," \
		${WRKSRC}/modules/gmp.lsp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newlisp ${PREFIX}/bin/

	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${MODULES:S,^,${WRKSRC}/modules/,:S,$,.lsp,} ${DATADIR}/

	${INSTALL_MAN} ${WRKSRC}/doc/newlisp.1 ${PREFIX}/man/man1/

.if defined(WITH_TK)
	${INSTALL_SCRIPT} ${WRKSRC}/newlisp-tk/newlisp-tk.tcl \
		${PREFIX}/bin/newlisp-tk
	${MKDIR} ${DATADIR}/newlisp-tk/
	@(cd ${WRKSRC}/newlisp-tk && \
		${COPYTREE_SHARE} \* ${DATADIR}/newlisp-tk/)
	${INSTALL_MAN} ${WRKSRC}/doc/newlisp-tk.1 ${PREFIX}/man/man1/
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${MKDIR} ${EXAMPLESDIR}/

	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/init.lsp.example ${EXAMPLESDIR}/

	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
