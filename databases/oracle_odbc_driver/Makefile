# New ports collection makefile for:	oracle_odbc_driver
# Date created:				8 Aug 2005
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	oracle_odbc_driver
PORTVERSION=	0.5.6
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://home.fnal.gov/~dbox/oracle/odbc/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Oracle Open Source ODBC driver

LIB_DEPENDS=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS=	--with-unixODBC=${LOCALBASE}

BUILD_DEPENDS=	${ORACLE_HOME}/lib/libclntst8.a:${PORTSDIR}/databases/oracle8-client
RUN_DEPENDS=	${ORACLE_HOME}/lib/libclntst8.a:${PORTSDIR}/databases/oracle8-client

WRKSRC=		${WRKDIR}/${PORTNAME}
ORACLE_HOME=	${LOCALBASE}/oracle8-client

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ORACLE_HOME="${ORACLE_HOME}" \
		LIBS="`${CAT} ${ORACLE_HOME}/lib/sysliblist`"\
		AUTOHEADER=true
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${REINPLACE_CMD} -e 's/-lclntst8 -lcompat -lpthread -lm/-lclntst8 -lcompat ${PTHREAD_LIBS} -lm/' ${WRKSRC}/configure

.include <bsd.port.mk>
