# New ports collection makefile for:	Another HTML-lint
# Date created:		29 Sep 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	another-htmllint
PORTVERSION=	20040725
CATEGORIES=	japanese www
MASTER_SITES=	http://dist.bsdlab.org/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Another HTML-lint (all messages are written in Japanese)

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${JCODE}:${PORTSDIR}/japanese/p5-Jcode

USE_ZIP=	YES
WRKSRC=		${WRKDIR}
EXTRACT_BEFORE_ARGS=	-a -q

DIR=		${PREFIX}/share/htmllint
PM=		htmllint.pm RFC2396.pm htmllint.env
RULE=		*.rul
HTML=		*.cgi *.html *.gif *.css
SEDSUB=		${SED} -e 's@%PREFIX%@${PREFIX}@'

# Please set this!
HTMLLINT_ADMIN?=	kuriyama@FreeBSD.org

do-build:
	@${SEDSUB} ${FILESDIR}/htmllint > ${WRKSRC}/htmllint
	@${SEDSUB} ${WRKSRC}/htmllintenv > ${WRKSRC}/htmllint.env
	@${SEDSUB} ${WRKSRC}/htmllint.cgi > ${WRKSRC}/htmllint.cgi.new
	@${MV} ${WRKSRC}/htmllint.cgi.new ${WRKSRC}/htmllint.cgi
	@${SED} -i.bak -e 's|^</address>|</address><br>Maintained by <address>${HTMLLINT_ADMIN}</address>|' ${WRKSRC}/*.html
.if exists(${LOCALBASE}/bin/w3m)
	@${ECHO_MSG} "Find w3m."
	@${SED} -i.bak -e 's|^#$$W3M|$$W3M|' ${WRKSRC}/htmllint.env
.endif

do-install:
	${MKDIR} ${DIR}/rule ${DIR}/html
	cd ${WRKSRC} && ${INSTALL_SCRIPT} htmllint ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${HTML} ${DIR}/html
	cd ${WRKSRC} && ${INSTALL_DATA} ${PM} ${DIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${RULE} ${DIR}/rule

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
JCODE=	${SITE_PERL}/${PERL_ARCH}/Jcode.pm
.else
JCODE=	${SITE_PERL}/Jcode.pm
.endif

.include <bsd.port.post.mk>
