# Created by: ijliao
# $FreeBSD$

PORTNAME=	dbtool
PORTVERSION=	1.8
CATEGORIES=	databases
MASTER_SITES=	http://www.daemon.de/idisk/Apps/dbtool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Store and retrieve data in a key/value format in a hash database

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

OPTIONS_DEFINE=	BDB EXAMPLES

EXAMPLES_RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

USES=		gmake
REINPLACE_ARGS=	-i ""

SH2BASH=	samples/account-db/accdb
UB2PFX=		samples/locate/locate samples/locate/updatedb
EXTRACT_AFTER_ARGS+=	--no-same-permissions --no-same-owner --exclude '*~'

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	48+
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LIBS+=		-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}
CONFIGURE_ARGS+=	--with-berkeley
.else
LIB_DEPENDS+=	libgdbm.so:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--without-berkeley
.endif

post-patch:
	${REINPLACE_CMD} -e "s,stdin,input,g" ${WRKSRC}/dbtool.cc ${WRKSRC}/engine.cc ${WRKSRC}/engine.h
.if ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e "s|/bin/sh|${LOCALBASE}/bin/bash|" ${SH2BASH:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${UB2PFX:S|^|${WRKSRC}/|}
	${RM} ${UB2PFX:C|.*|${WRKSRC}/&.orig|}

post-install:
	#@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
