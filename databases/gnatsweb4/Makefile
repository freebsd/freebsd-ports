# Created by: Oliver Eikemeier <eikemeier@fillmore-labs.com>
# $FreeBSD$

PORTNAME=	gnatsweb
PORTVERSION=	4.00
PORTREVISION=	6
CATEGORIES=	databases devel www
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnatsweb, a GNATS web interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-MIME-Base64>=0:converters/p5-MIME-Base64

USES=		apache:run,2.2+ perl5 shebangfix
SHEBANG_FILES=	gnatsweb.pl
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

CGI_DIR?=	${WWWDIR}/cgi-bin

PLIST_SUB=	CGI_DIR="${CGI_DIR:S,^${PREFIX}/,,}"

PORTDOCS=	CUSTOMIZE CUSTOMIZE.cb CUSTOMIZE.vars \
		ChangeLog INSTALL NEWS README TROUBLESHOOTING

PORTEXAMPLES=	gnatsweb-site-example.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${CGI_DIR} \
		${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gnatsweb-site.pl \
		${STAGEDIR}${ETCDIR}/gnatsweb-site.pl.sample
	${INSTALL_SCRIPT} ${WRKSRC}/gnatsweb.pl ${STAGEDIR}${CGI_DIR}
	${LN} -s  ${ETCDIR}/gnatsweb-site.pl ${STAGEDIR}${CGI_DIR}
	${INSTALL_DATA} ${WRKSRC}/gnatsweb.html ${STAGEDIR}${CGI_DIR}

do-install-DOCS-on:
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
.for example in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${example} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
