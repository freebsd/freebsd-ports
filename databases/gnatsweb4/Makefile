# Created by: Oliver Eikemeier <eikemeier@fillmore-labs.com>
# $FreeBSD$

PORTNAME=	gnatsweb
PORTVERSION=	4.00
PORTREVISION=	2
CATEGORIES=	databases devel www
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnatsweb, a GNATS web interface

RUN_DEPENDS=	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64

USE_APACHE_RUN=	22+

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

CGI_DIR?=	${WWWDIR}/cgi-bin

PLIST_SUB=	CGI_DIR="${CGI_DIR:S,^${PREFIX}/,,}"

PORTDOCS=	CUSTOMIZE CUSTOMIZE.cb CUSTOMIZE.vars \
		ChangeLog INSTALL NEWS README TROUBLESHOOTING

PORTEXAMPLESS=	gnatsweb-site-example.pl

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/gnatsweb-site.pl  ${STAGEDIR}${ETCDIR}/gnatsweb-site.pl.default
	${INSTALL_DATA} ${WRKSRC}/gnatsweb-site.pl ${STAGEDIR}${ETCDIR}/gnatsweb-site.pl.sample
	@${MKDIR} ${STAGEDIR}${CGI_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/gnatsweb.pl ${STAGEDIR}${CGI_DIR}
	${LN} -s  ${ETCDIR}/gnatsweb-site.pl ${STAGEDIR}${CGI_DIR}
	${INSTALL_DATA} ${WRKSRC}/gnatsweb.html ${STAGEDIR}${CGI_DIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for doc in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${STAGEDIR}${DOCSDIR}; \
	done
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	for example in ${EXAMPLEFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${example} ${STAGEDIR}${EXAMPLESDIR}; \
	done

.include <bsd.port.mk>
