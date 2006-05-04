# New ports collection makefile for:    p5-Mysql-modules
# Date created:				24 August 1999
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	${TCL_NODOT}-sql
PORTVERSION=	20000114
PORTREVISION=	5
CATEGORIES=	databases ${TCL_NODOT}
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tcl-sql
DISTNAME=	tcl-sql-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	TCL module for accessing MySQL databases

LIB_DEPENDS=	mysqlclient:${PORTSDIR}/databases/mysql41-client
BUILD_DEPENDS=	tclsh${TCL_VERSION}:${PORTSDIR}/lang/${TCL_NODOT}

TCL_VERSION?=	8.4	# Only this needs changing to switch TCL-version
TCL_NODOT=	tcl${TCL_VERSION:S/.//}
WRKSRC=		${WRKDIR}/tcl-sql/
LIB_NAME=	libTclMySQL.so.1
PLIST_SUB=	TCL_VERSION=tcl${TCL_VERSION} LIB_NAME=${LIB_NAME}
MAKE_ARGS+=	SHLIB_NAME=${LIB_NAME} ${PLIST_SUB}
REINPLACE_ARGS=	-i ""
MAKEFILE=	${FILESDIR}/Makefile.bsd

post-patch:
	@${REINPLACE_CMD} -e 's,^int ,static int ,' ${WRKSRC}/sql.cc

SQL_DIR=	${LOCALBASE}/lib/tcl${TCL_VERSION}/sql1.0

do-install:
	${MKDIR} ${SQL_DIR}
	${INSTALL_DATA} ${WRKSRC}/obj/libTclMySQL.so.* ${SQL_DIR}
	${ECHO} "package ifneeded sql 1.0 \
		{load ${SQL_DIR}/${LIB_NAME} sql}" \
		> ${SQL_DIR}/pkgIndex.tcl
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcl-MySQL/
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${WRKSRC}/docs/*.txt \
		${PREFIX}/share/doc/tcl-MySQL/
.endif

.include <bsd.port.mk>
