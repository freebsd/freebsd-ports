# Created by: ijliao
# $FreeBSD$

PORTNAME=	dbtool
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.daemon.de/idisk/Apps/dbtool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Store and retrieve data in a key/value format in a hash database

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	BDB EXAMPLES

BDB_LIB_DEPENDS=	libdb3.so:${PORTSDIR}/databases/db3
BDB_CPPFLAGS=		-I${LOCALBASE}/include/db3
BDB_CONFIGURE_ON=	--with-berkeley
BDB_LIB_DEPENDS_OFF=	libgdbm.so:${PORTSDIR}/databases/gdbm

EXAMPLES_RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USES=		gmake
REINPLACE_ARGS=	-i ""

SH2BASH=	samples/account-db/accdb
UB2PFX=		samples/locate/locate samples/locate/updatedb

post-patch:
.for file in dbtool.cc engine.cc engine.h
	@${REINPLACE_CMD} -e "s,stdin,input,g" ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e "s,==,=,g" ${WRKSRC}/configure
.if !defined(NOPORTDOCS)
.for file in ${SH2BASH}
	@${REINPLACE_CMD} -e "s|/bin/sh|${LOCALBASE}/bin/bash|" ${WRKSRC}/${file}
.endfor
.for file in ${UB2PFX}
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/${file}
	@${RM} ${WRKSRC}/${file}.orig
	@${RM} ${WRKSRC}/${file}~
.endfor
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${CP} -Rp ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
