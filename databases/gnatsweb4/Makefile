# New ports collection makefile for:	gnatsweb4
# Date created:				20 Sep 2003
# Whom:					Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=		gnatsweb
PORTVERSION=		4.00
PORTREVISION=	1
CATEGORIES=		databases devel www
MASTER_SITES=		GNU

MAINTAINER=		pgollucci@FreeBSD.org
COMMENT=		Gnatsweb, a GNATS web interface

RUN_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0+

USE_PERL5_RUN=		yes
NO_BUILD=		yes

CGI_DIR?=		${WWWDIR}/cgi-bin

PLIST_SUB=		CGI_DIR="${CGI_DIR:S,^${PREFIX}/,,}"

PORTDOCS=		CUSTOMIZE CUSTOMIZE.cb CUSTOMIZE.vars \
			ChangeLog INSTALL NEWS README TROUBLESHOOTING

PORTEXAMPLESS=		gnatsweb-site-example.pl

do-install:
	@${MKDIR} ${ETCDIR}/
	@${INSTALL_DATA} ${WRKSRC}/gnatsweb-site.pl  ${ETCDIR}/gnatsweb-site.pl.default
	@[ -f ${ETCDIR}/gnatsweb-site.pl ] || \
		${INSTALL_DATA} ${WRKSRC}/gnatsweb-site.pl ${ETCDIR}/
	@${MKDIR} ${CGI_DIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/gnatsweb.pl ${CGI_DIR}/
	@${LN} -s  ${ETCDIR}/gnatsweb-site.pl ${CGI_DIR}/
	@${INSTALL_DATA} ${WRKSRC}/gnatsweb.html ${CGI_DIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@for doc in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${DOCSDIR}/; \
	done
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/
	@for example in ${EXAMPLEFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${example} ${EXAMPLESDIR}/; \
	done
.endif

.include <bsd.port.mk>
