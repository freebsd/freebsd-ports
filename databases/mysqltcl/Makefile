# New ports collection makefile for:	mysqltcl
# Date created:				August 31, 1999
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mysqltcl
PORTVERSION=	1.53
CATEGORIES=	databases tcl83
MASTER_SITES=	http://telia.dl.sourceforge.net/mirrors/mysql/Downloads/Contrib/

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client \
		${TCL_NODOT}:${PORTSDIR}/lang/${TCL_NODOT}

TCL_VERSION?=	tcl8.3
TCL_NODOT=	${TCL_VERSION:S/.//}
SQL_DIR=	${PREFIX}/lib/${TCL_VERSION}/mysqltcl
PLIST_SUB+=	TCL_VERSION=${TCL_VERSION} LIB_NAME=${LIB_NAME}
MANN=		mysqltcl.n

do-build:
	cd ${WRKSRC} && ${MAKE} PREFIX="${PREFIX}" \
		TCL_VERSION=${TCL_VERSION} TCL_NODOT=${TCL_NODOT} \
		-f ${FILESDIR}/Makefile.bsd ${LIB_NAME}

do-install:
	${MKDIR} ${SQL_DIR}
	${INSTALL_DATA} ${WRKSRC}/${LIB_NAME} ${SQL_DIR}
	${ECHO} "package ifneeded mysql 1.53 {load ${SQL_DIR}/${LIB_NAME}}" \
		> ${SQL_DIR}/pkgIndex.tcl
	${INSTALL_MAN} ${WRKSRC}/${MANN} ${PREFIX}/man/mann

.include <bsd.port.mk>

LIB_NAME!=	${MAKE} -f ${FILESDIR}/Makefile.bsd printname
