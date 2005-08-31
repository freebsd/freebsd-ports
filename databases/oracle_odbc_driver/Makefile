# New ports collection makefile for:	oracle_odbc_driver
# Date created:				8 Aug 2005
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oracle_odbc_driver
PORTVERSION=	0.5.5
CATEGORIES=	databases
MASTER_SITES=	http://fndapl.fnal.gov/~dbox/oracle/odbc/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Oracle Open Source ODBC driver

OPTIONS=	UNIXODBC	"Build with unixODBC" on \
		IODBC		"Build with iODBC" off \

.if !defined(WITH_UNIXODBC) && !defined(WITH_IODBC)
WITH_UNIXODBC=	yes
.endif

.if defined(WITH_UNIXODBC)
LIB_DEPENDS=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS=	--with-unixODBC=${LOCALBASE}
.endif

.if defined(WITH_IODBC)
LIB_DEPENDS=	iodbc:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS=	--without-unixODBC
.endif

BUILD_DEPENDS=	${ORACLE_HOME}/lib/libclntst8.a:${PORTSDIR}/databases/oracle8-client
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
ORACLE_HOME=	${LOCALBASE}/oracle8-client

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ORACLE_HOME="${ORACLE_HOME}" \
		LIBS="`${CAT} ${ORACLE_HOME}/lib/sysliblist`"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_AUTOTOOLS=	libtool:13
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
