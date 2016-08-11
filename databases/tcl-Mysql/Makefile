# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	${TCL_NODOT}-sql
PORTVERSION=	20000114
PORTREVISION=	7
CATEGORIES=	databases tcl
MASTER_SITES=	SF/tcl-sql/tcl-sql/${PORTVERSION}
DISTNAME=	tcl-sql-${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	TCL module for accessing MySQL databases

OPTIONS_DEFINE=	DOCS

PATCH_DEPENDS=	rcsdiff:devel/rcs

USES=		mysql tcl tar:tgz
TCL_NODOT=	tcl${TCL_VER:S/.//}
WRKSRC=		${WRKDIR}/tcl-sql
LIB_NAME=	libTclMySQL.so.1
MAKE_ARGS+=	SHLIB_NAME=${LIB_NAME} ${PLIST_SUB} TCL_VERSION=tcl${TCL_VER}
REINPLACE_ARGS=	-i ""
MAKEFILE=	${FILESDIR}/Makefile.bsd

DOCSDIR?=	${PREFIX}/share/doc/tcl-MySQL

PLIST_FILES=	lib/sql1.0/${LIB_NAME} \
		lib/sql1.0/pkgIndex.tcl
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's,^int ,static int ,' ${WRKSRC}/sql.cc

SQL_DIR=	lib/sql1.0

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SQL_DIR}
	${INSTALL_DATA} ${WRKSRC}/obj/libTclMySQL.so.* ${STAGEDIR}${PREFIX}/${SQL_DIR}
	${ECHO} "package ifneeded sql 1.1 \
		{load ${SQL_DIR}/${LIB_NAME} sql}" \
		> ${STAGEDIR}${PREFIX}/${SQL_DIR}/pkgIndex.tcl
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${WRKSRC}/docs/*.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
