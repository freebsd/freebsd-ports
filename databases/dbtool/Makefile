# ex:ts=8
# New ports collection makefile for:	dbtool
# Date created:			Apr 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbtool
PORTVERSION=	1.5
PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.daemon.de/scip/Apps/dbtool/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

.if defined(WITH_BERKELEY_DB)
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
DB_INC=		-I${LOCALBASE}/include/db3
CONFIGURE_ARGS=	--with-berkeley
.else
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include ${DB_INC}"

USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=	dbtool.1

post-extract:
.if !defined(WITH_BERKELEY_DB)
	@${ECHO_MSG}
	@${ECHO_MSG} " Build with gdbm by default. "
	@${ECHO_MSG} " If you want to use BerkeleyDB, you can build with WITH_BERKELEY_DB=yes"
	@${ECHO_MSG}
.endif

post-patch:
.for file in dbtool.cc engine.cc engine.h
	@${REINPLACE_CMD} -e "s,stdin,input,g" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s,==,=,g" ${WRKSRC}/configure

.include <bsd.port.mk>
