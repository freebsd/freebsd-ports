# New ports collection makefile for: sirc
# Date created:                      4 May 1998
# Whom:                              Doug Barton <Doug@gorean.org>
#
# $FreeBSD$
#
# If you need SOCKS support, define SOCKS_SERVER with
# the name of your SOCKS proxy and remove the '#'.
# You should also check the default port and DNS
# setting in ${PREFIX}/bin/sirc after installation.
#
# SOCKS_SERVER= your.socks.proxy

PORTNAME=	sirc
PORTVERSION=	2.211
CATEGORIES=	irc
MASTER_SITES=	http://www.iagora.com/~espel/sirc/ \
		http://dougbarton.net/FreeBSD/Downloads/

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	Small (150k), fast, perl-based IRC client

USE_PERL5=	yes

.if exists(/usr/bin/perl5)
SHORT_PERL5=/usr/bin/perl5
.else
SHORT_PERL5=${PREFIX}/bin/perl5
.endif

post-extract:
.if !defined(SOCKS_SERVER)
	@${ECHO_MSG} ''
	@${ECHO_MSG} "SOCKS proxy support is available with this client."
	@${ECHO_MSG} "If you need SOCKS support edit the Makefile in this"
	@${ECHO_MSG} "directory according to the instructions at the top of it."
	@${ECHO_MSG} "Then do 'make clean', 'make deinstall' (if needed)"
	@${ECHO_MSG} "then 'make install'."
	@${ECHO_MSG} ''
.endif

pre-patch:
	@${CP} ${SCRIPTDIR}/sirc-proto ${WRKSRC}

do-patch:
.if defined(SOCKS_SERVER)
	@${PATCH} ${PATCH_DIST_ARGS} < ${PATCHDIR}/patch-aa
	@${SED} 's:SOCKS_SERVER\=:SOCKS_SERVER\=${SOCKS_SERVER}:' \
		${WRKSRC}/sirc-proto > ${WRKSRC}/sirc-proto.1
	@${SED} 's:PREFIX.SED:${PREFIX}:' ${WRKSRC}/sirc-proto.1 \
		> ${WRKSRC}/sirc-proto.2
	@${SED} 's:PERL5.SED:${SHORT_PERL5}:' ${WRKSRC}/sirc-proto.2 \
		> ${WRKSRC}/sirc
.else
	@${SED} 's:PREFIX.SED:${PREFIX}:' ${WRKSRC}/sirc-proto \
		> ${WRKSRC}/sirc-proto.1
	@${SED} 's:PERL5.SED:${SHORT_PERL5}:' ${WRKSRC}/sirc-proto.1 \
		> ${WRKSRC}/sirc
.endif

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/ssfe.c -o ${WRKSRC}/ssfe -ltermcap

do-install:
	${MKDIR} ${PREFIX}/libexec/sirc
	${INSTALL_DATA} ${WRKSRC}/n0thing.pl ${PREFIX}/libexec/sirc
	${INSTALL_DATA} ${WRKSRC}/sirc.help.gz ${PREFIX}/libexec/sirc
	${INSTALL_DATA} ${WRKSRC}/socks.pl ${PREFIX}/libexec/sirc
	${INSTALL_SCRIPT} ${WRKSRC}/dsirc ${PREFIX}/libexec/sirc
	${INSTALL_PROGRAM} ${WRKSRC}/ssfe ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sirc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ssfe.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/sirc.1 ${PREFIX}/man/man1
.if defined(SOCKS_SERVER)
	${ECHO_CMD} '&load("socks.pl");' >> ${PREFIX}/libexec/sirc/sircrc.pl
.endif
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/libexec/sirc
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/libexec/sirc
	${INSTALL_DATA} ${WRKSRC}/PROGRAMMING ${PREFIX}/libexec/sirc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/libexec/sirc
	${INSTALL_DATA} ${WRKSRC}/README.socks ${PREFIX}/libexec/sirc
.endif

MAN1=		sirc.1 ssfe.1

.include <bsd.port.mk>
