# New ports collection makefile for: sirc
# Date created:			4 May 1998
# Whom:				Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	sirc
PORTVERSION=	2.211
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	http://www.iagora.com/~espel/sirc/ \
		http://dougbarton.us/Downloads/sirc/ \
		http://www.iagora.com/~espel/sirc/scripts/:s \
		http://dougbarton.us/Downloads/sirc/scripts/:s
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	sirc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Small (150k), fast, perl-based IRC client

LICENSE=	GPLv2

USE_PERL5=	yes

OPTIONS=	IPV6 "Support for IPv6 transport" on \
		SIRC_SCRIPTS "Additional scripts for the client" on \
		SOCKS "Support for IRC'ing through a SOCKS proxy" off

SUB_FILES=	sirc

MAN1=		ssfe.1 sirc.1

PORTDOCS=	ChangeLog PROGRAMMING README

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IPV6)
RUN_DEPENDS=	${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6
EXTRA_PATCHES=	${PATCHDIR}/dsirc-ipv6
.else
EXTRA_PATCHES=	${PATCHDIR}/dsirc-minimal
.endif

.if !defined(WITHOUT_SIRC_SCRIPTS)
DISTFILES+=	adcc.pl:s akickban.pl:s avoice.pl:s country.pl:s finger.pl:s \
		ftp.pl:s howl.pl:s lastlog.pl:s nocolor.pl:s patattack.pl:s \
		prefix.pl:s quiet.pl:s quit.pl:s thx.pl:s www.pl:s yiff.pl:s
PLIST_SUB+=	SCRIPTS=""
.else
PLIST_SUB+=	SCRIPTS="@comment "
.endif

.if defined(WITH_SOCKS)
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
.if !defined(WITHOUT_SIRC_SCRIPTS)
.for file in adcc.pl akickban.pl avoice.pl country.pl finger.pl ftp.pl \
	howl.pl lastlog.pl nocolor.pl patattack.pl prefix.pl quiet.pl \
	quit.pl thx.pl www.pl yiff.pl
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${file} ${SIRCLIBDIR}
.endfor
.endif
.if defined(WITH_SOCKS)
	${INSTALL_DATA} ${WRKSRC}/socks.pl ${SIRCLIBDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.if defined(WITH_SOCKS)
	${INSTALL_DATA} ${WRKSRC}/README.socks ${DOCSDIR}
.endif
.endif

post-install:
.if defined(WITH_SOCKS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
