# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	oracle_odbc_driver
PORTVERSION=	0.5.6
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://home.fnal.gov/~dbox/oracle/odbc/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oracle Open Source ODBC driver

BROKEN=		unfetchable

LIB_DEPENDS=	libodbc.so:databases/unixODBC
CONFIGURE_ARGS=	--with-unixODBC=${LOCALBASE}

BUILD_DEPENDS=	${ORACLE_HOME}/lib/libclntst8.a:databases/oracle8-client
RUN_DEPENDS=	${ORACLE_HOME}/lib/libclntst8.a:databases/oracle8-client

WRKSRC=		${WRKDIR}/${PORTNAME}
ORACLE_HOME=	${LOCALBASE}/oracle8-client

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ORACLE_HOME="${ORACLE_HOME}" \
		AUTOHEADER=true
LIBS+=		`${CAT} ${ORACLE_HOME}/lib/sysliblist`
USE_LDCONFIG=	yes

.include <bsd.port.mk>
