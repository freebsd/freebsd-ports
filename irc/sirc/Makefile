# $FreeBSD$

PORTNAME=	sirc
PORTVERSION=	2.211
PORTREVISION=	2
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

RUN_DEPENDS=	p5-Perl4-CoreLibs>=0:${PORTSDIR}/devel/p5-Perl4-CoreLibs

USES=		perl5

OPTIONS_DEFINE=	DOCS IPV6 SIRC_SCRIPTS SOCKS
OPTIONS_DEFAULT=SIRC_SCRIPTS
OPTIONS_SUB=	yes

IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>0:${PORTSDIR}/net/p5-IO-Socket-INET6
IPV6_EXTRA_PATCHES=	${PATCHDIR}/dsirc-ipv6

SIRC_SCRIPTS_DESC= 	Additional scripts for the client
SIRC_SCRIPTS_DISTFILES=	${SIRC_SCRIPTS:S|$|:s|}

SUB_FILES=	sirc

PORTDOCS=	ChangeLog PROGRAMMING README
SIRC_SCRIPTS=	adcc.pl akickban.pl avoice.pl country.pl finger.pl ftp.pl \
		howl.pl lastlog.pl nocolor.pl patattack.pl prefix.pl quiet.pl \
		quit.pl thx.pl www.pl yiff.pl

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MIPV6}
EXTRA_PATCHES=	${PATCHDIR}/dsirc-minimal
.endif

.if ${PORT_OPTIONS:MSOCKS}
PKGMESSAGE=	${FILESDIR}/pkg-message-socks
.endif

pre-patch:
	@${CP} ${WRKSRC}/dsirc ${WRKSRC}/dsirc.prepatch
	@${SED} -e "1s|^#!/usr/local/bin/perl|#!${PREFIX}/bin/perl|" \
		-e "s#irc.primenet.com#irc.efnet.org#" \
		${WRKSRC}/dsirc.prepatch > ${WRKSRC}/dsirc

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/ssfe.c -o ${WRKSRC}/ssfe -ltermcap

SIRCLIBDIR=	${STAGEDIR}${PREFIX}/libexec/sirc
do-install:
	@${MKDIR} ${SIRCLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/n0thing.pl ${SIRCLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/sirc.help.gz ${SIRCLIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/dsirc ${SIRCLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ssfe ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/sirc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ssfe.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sirc.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MSIRC_SCRIPTS}
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${SIRC_SCRIPTS} \
		${SIRCLIBDIR})
.endif
	${INSTALL_DATA} ${WRKSRC}/socks.pl ${SIRCLIBDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.socks ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
