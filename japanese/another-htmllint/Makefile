# $FreeBSD$

PORTNAME=	another-htmllint
PORTVERSION=	20111128
PORTREVISION=	1
CATEGORIES=	japanese www
MASTER_SITES=	http://openlab.ring.gr.jp/k16/htmllint/archives/
DISTNAME=	htmllint

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Another HTML-lint (all messages are written in Japanese)

LICENSE=	AnotherHTMLlint
LICENSE_NAME=	Another HTML-lint License
LICENSE_TEXT=	See http://openlab.ring.gr.jp/k16/htmllint/index.html (Written in Japanese)
LICENSE_PERMS=	no-dist-sell no-pkg-sell

RUN_DEPENDS=	p5-CGI.pm>=0:www/p5-CGI.pm \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-libwww>=0:www/p5-libwww \
		ja-p5-Jcode>=0:japanese/p5-Jcode

USES=		dos2unix perl5 shebangfix zip
WRKSRC=		${WRKDIR}
DOS2UNIX_FILES=	readme.txt
SHEBANG_FILES=	htmllint.cgi tagslist.cgi
SUB_FILES=	htmllint pkg-message
SUB_LIST+=	PERL=${PERL}
NO_ARCH=	YES

OPTIONS_DEFINE=	W3M
W3M_DESC=	Use w3m to show rendering result
W3M_RUN_DEPENDS=	w3m>0:www/w3m

PM=		htmllint.pm RFC2396.pm htmllint.env
RULE=		*.rul
HTML=		*.cgi *.html *.gif *.css
SEDSUB=		${SED} -i.bak -e 's@%%PREFIX%%@${PREFIX}@ ; s@%%DATADIR%%@${DATADIR}@'

# Please set this!
HTMLLINT_ADMIN?=	kuriyama@FreeBSD.org

do-build:
	@${SEDSUB} ${WRKSRC}/htmllintenv
	@${MV} ${WRKSRC}/htmllintenv ${WRKSRC}/htmllint.env
	@${SEDSUB} ${WRKSRC}/htmllint.cgi
	@${SED} -i.bak -e 's|^</address>|</address><br>Maintained by <address>${HTMLLINT_ADMIN}</address>|' ${WRKSRC}/*.html

do-build-W3M-on:
	@${SED} -i.bak -e 's|^#$$W3M|$$W3M|' ${WRKSRC}/htmllint.env

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/rule ${STAGEDIR}${DATADIR}/html
	cd ${WRKSRC} && ${INSTALL_SCRIPT} htmllint ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${HTML} ${STAGEDIR}${DATADIR}/html
	cd ${WRKSRC} && ${INSTALL_DATA} ${PM} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${RULE} ${STAGEDIR}${DATADIR}/rule

.include <bsd.port.mk>
