# New ports collection makefile for:    p5-Mysql-modules
# Version required:			990813
# Date created:				24 August 1999
# Whom:	      				Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

DISTNAME=	tcl-sql-990813
CATEGORIES=	databases tcl80
MASTER_SITES=	http://www.binevolve.com/~tdarugar/tcl-sql/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client
RUN_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80

WRKSRC=		${WRKDIR}/tcl-sql/

do-build:
	cd ${WRKSRC} && ${MAKE} PREFIX="${PREFIX}" -f ${FILESDIR}/Makefile.bsd

SQL_DIR=	${PREFIX}/lib/tcl8.0/sql1.0

do-install:
	${MKDIR} ${SQL_DIR}
	${INSTALL_DATA} ${WRKSRC}/obj/libTclMySQL.so.* ${SQL_DIR}
	${ECHO} "package ifneeded sql 1.0 \
		{load \$$tcl_library/sql1.0/`${MAKE} -f \
			 ${FILESDIR}/Makefile.bsd printname` sql}" \
		> ${SQL_DIR}/pkgIndex.tcl
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tcl-MySQL/
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${PREFIX}/share/doc/tcl-MySQL/
.endif

.include <bsd.port.mk>
