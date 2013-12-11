# Created by: ijliao
# $FreeBSD$

PORTNAME=	dbtool
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://www.daemon.de/idisk/Apps/dbtool/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Store and retrieve data in a key/value format in a hash database

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

.if defined(WITH_BERKELEY_DB)
LIB_DEPENDS+=	libdb3.so:${PORTSDIR}/databases/db3
DB_INC=		-I${LOCALBASE}/include/db3
CONFIGURE_ARGS=	--with-berkeley
.else
LIB_DEPENDS+=	libgdbm.so:${PORTSDIR}/databases/gdbm
.endif
.if !defined(NOPORTDOCS)
RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash
.endif

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include ${DB_INC}

USE_GMAKE=	yes
REINPLACE_ARGS=	-i ""

MAN1=	dbtool.1

SH2BASH=	samples/account-db/accdb
UB2PFX=		samples/locate/locate samples/locate/updatedb

NO_STAGE=	yes
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rp ${WRKSRC}/samples/* ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
