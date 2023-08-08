PORTNAME=	srvx
PORTVERSION=	1.3.1
CATEGORIES=	irc net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Services for ircu P10 protocol networks
WWW=		http://www.srvx.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-getopt

SUB_FILES=	pkg-message

PLIST_FILES=	bin/srvx etc/srvx.conf.example etc/sockcheck.conf.example
PORTDOCS=	*

OPTIONS_DEFINE=	BAHAMUT DEBUG DOCS
OPTIONS_DEFAULT=	BAHAMUT
BAHAMUT_DESC=	Enable Bahamut protocol (P10 is default)

DEBUG_CONFIGURE_ON=	--enable-debug
BAHAMUT_CONFIGURE_ON=	--with-protocol=bahamut

.include <bsd.port.options.mk>

.if ${ARCH:Marmv?} || ${ARCH} == powerpc
CONFIGURE_ENV+=	ac_cv_fmt_time_t="\"%lli\""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|srvx\.conf|${PREFIX}/etc/srx.conf|' \
		${WRKSRC}/src/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/srvx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.conf.example ${STAGEDIR}${PREFIX}/etc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/*.help ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
