# New ports collection makefile for:    p5-Mysql-modules
# Date created:				24 August 1999
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	tcl-sql
PORTVERSION=	20000114
PORTREVISION=	1
CATEGORIES=	databases ${TCL_NODOT}
MASTER_SITES=	http://www.binevolve.com/~tdarugar/tcl-sql/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS=	${TCL_VERSION:S/tcl/tclsh/}:${PORTSDIR}/lang/${TCL_NODOT}

TCL_VERSION?=	tcl8.3	# Only this needs changing to switch TCL-version
TCL_NODOT=	${TCL_VERSION:S/.//}
WRKSRC=		${WRKDIR}/tcl-sql/
PLIST_SUB=	TCL_VERSION=${TCL_VERSION} LIB_NAME=${LIB_NAME}

do-build:
	cd ${WRKSRC} && ${MAKE} ${PLIST_SUB} -f ${FILESDIR}/Makefile.bsd

SQL_DIR=	${LOCALBASE}/lib/${TCL_VERSION}/sql1.0

do-install:
	${MKDIR} ${SQL_DIR}
	${INSTALL_DATA} ${WRKSRC}/obj/libTclMySQL.so.* ${SQL_DIR}
	${ECHO} "package ifneeded sql 1.0 \
		{load ${SQL_DIR}/${LIB_NAME} sql}" \
		> ${SQL_DIR}/pkgIndex.tcl
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcl-MySQL/
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${PREFIX}/share/doc/tcl-MySQL/
.endif

.include <bsd.port.mk>

LIB_NAME!=	${MAKE} -f ${FILESDIR}/Makefile.bsd printname
