# New ports collection makefile for:    p5-Mysql-modules
# Date created:				24 August 1999
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	${TCL_NODOT}-sql
PORTVERSION=	20000114
PORTREVISION=	7
CATEGORIES=	databases tcl
MASTER_SITES=	SF/tcl-sql/tcl-sql/${PORTVERSION}
DISTNAME=	tcl-sql-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	TCL module for accessing MySQL databases

LIB_DEPENDS=	mysqlclient:${PORTSDIR}/databases/mysql41-client

USE_TCL=	83+
TCL_NODOT=	tcl${TCL_VER:S/.//}
WRKSRC=		${WRKDIR}/tcl-sql/
LIB_NAME=	libTclMySQL.so.1
PLIST_SUB=	TCL_VERSION=tcl${TCL_VER} LIB_NAME=${LIB_NAME}
MAKE_ARGS+=	SHLIB_NAME=${LIB_NAME} ${PLIST_SUB}
REINPLACE_ARGS=	-i ""
MAKEFILE=	${FILESDIR}/Makefile.bsd

DOCSDIR?=	${PREFIX}/share/doc/tcl-MySQL

post-patch:
	@${REINPLACE_CMD} -e 's,^int ,static int ,' ${WRKSRC}/sql.cc

SQL_DIR=	${LOCALBASE}/lib/tcl${TCL_VER}/sql1.0

do-install:
	${MKDIR} ${SQL_DIR}
	${INSTALL_DATA} ${WRKSRC}/obj/libTclMySQL.so.* ${SQL_DIR}
	${ECHO} "package ifneeded sql 1.1 \
		{load ${SQL_DIR}/${LIB_NAME} sql}" \
		> ${SQL_DIR}/pkgIndex.tcl
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${WRKSRC}/docs/*.txt \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
