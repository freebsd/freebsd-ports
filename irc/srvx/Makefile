# Created by: Walter Venable <weaseal@hotmail.com>
# $FreeBSD$

PORTNAME=	srvx
PORTVERSION=	1.3.1
CATEGORIES=	irc net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of services for ircu P10 protocol networks

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	PROTOCOL_BAHAMUT DEBUG
OPTIONS_DEFAULT=	PROTOCOL_BAHAMUT
PROTOCOL_BAHAMUT_DESC=	Enables Bahamut protocol (P10 is default)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-getopt

SUB_FILES=	pkg-message

PORTDOCS=	chanserv.help 		\
		global.help 		\
		mod-helpserv.help	\
		mod-memoserv.help 	\
		mod-sockcheck.help	\
		modcmd.help 		\
		nickserv.help	 	\
		opserv.help 		\
		saxdb.help	 	\
		sendmail.help
PLIST_FILES=	bin/srvx 			\
		etc/srvx.conf.example		\
		etc/sockcheck.conf.example

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MPROTOCOL_BAHAMUT}
CONFIGURE_ARGS+=	--with-protocol=bahamut
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= "srvx.conf"|= "${PREFIX}/etc/srx.conf"|g' \
		${WRKSRC}/src/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/srvx ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.conf.example ${PREFIX}/etc
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.help ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
