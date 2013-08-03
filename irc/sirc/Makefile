# $FreeBSD$

PORTNAME=	sirc
PORTVERSION=	2.211
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	LOCAL/bdrewery/${PORTNAME} \
		http://www.iagora.com/~espel/sirc/ \
		LOCAL/bdrewery/${PORTNAME}/scripts:s \
		http://www.iagora.com/~espel/sirc/scripts/:s
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	sirc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small (150k), fast, perl-based IRC client

USES=		perl5

OPTIONS_DEFINE=	IPV6 SIRC_SCRIPTS SOCKS
OPTIONS_DEFAULT=IPV6 SIRC_SCRIPTS
IPV6_DESC=		Support for IPv6 transport
SIRC_SCRIPTS_DESC= 	Additional scripts for the clien
SOCKS_DESC=		Support for IRCing through a SOCKS proxy

SUB_FILES=	sirc

MAN1=		ssfe.1 sirc.1

PORTDOCS=	ChangeLog PROGRAMMING README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS=	p5-IO-Socket-INET6>0:${PORTSDIR}/net/p5-IO-Socket-INET6
EXTRA_PATCHES=	${PATCHDIR}/dsirc-ipv6
.else
EXTRA_PATCHES=	${PATCHDIR}/dsirc-minimal
.endif

.if ${PORT_OPTIONS:MSIRC_SCRIPTS}
DISTFILES+=	adcc.pl:s akickban.pl:s avoice.pl:s country.pl:s finger.pl:s \
		ftp.pl:s howl.pl:s lastlog.pl:s nocolor.pl:s patattack.pl:s \
		prefix.pl:s quiet.pl:s quit.pl:s thx.pl:s www.pl:s yiff.pl:s
PLIST_SUB+=	SCRIPTS=""
.else
PLIST_SUB+=	SCRIPTS="@comment "
.endif

.if ${PORT_OPTIONS:MSOCKS}
PKGMESSAGE=	${FILESDIR}/pkg-message-socks
PLIST_SUB+=	SOCKS=""
.else
PLIST_SUB+=	SOCKS="@comment "
.endif

pre-patch:
	@${CP} ${WRKSRC}/dsirc ${WRKSRC}/dsirc.prepatch
	@${SED} -e "1s|^#!/usr/local/bin/perl|#!${PREFIX}/bin/perl|" \
		-e "s#irc.primenet.com#irc.efnet.org#" \
		${WRKSRC}/dsirc.prepatch > ${WRKSRC}/dsirc

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/ssfe.c -o ${WRKSRC}/ssfe -ltermcap

SIRCLIBDIR=	${PREFIX}/libexec/sirc
do-install:
	@${MKDIR} ${SIRCLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/n0thing.pl ${SIRCLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/sirc.help.gz ${SIRCLIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/dsirc ${SIRCLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ssfe ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/sirc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ssfe.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sirc.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MSIRC_SCRIPTS}
.for file in adcc.pl akickban.pl avoice.pl country.pl finger.pl ftp.pl \
	howl.pl lastlog.pl nocolor.pl patattack.pl prefix.pl quiet.pl \
	quit.pl thx.pl www.pl yiff.pl
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${file} ${SIRCLIBDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MSOCKS}
	${INSTALL_DATA} ${WRKSRC}/socks.pl ${SIRCLIBDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.if ${PORT_OPTIONS:MSOCKS}
	${INSTALL_DATA} ${WRKSRC}/README.socks ${DOCSDIR}
.endif
.endif

post-install:
.if ${PORT_OPTIONS:MSOCKS}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
