# New ports collection makefile for:	gnatsweb4
# Date created:				20 Sep 2003
# Whom:					Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=		gnatsweb
PORTVERSION=		4.00
CATEGORIES=		databases devel www
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnatsweb

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Gnatsweb, a GNATS web interface

RUN_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

.ifdef WITH_APACHE2
RUN_DEPENDS+=		${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache2
.endif

USE_PERL5_RUN=		yes
NO_BUILD=		yes

CGI_DIR?=		${PREFIX}/www/cgi-bin

PLIST_SUB=		CGI_DIR="${CGI_DIR:S,^${PREFIX}/,,}"

DOCFILES=		CUSTOMIZE CUSTOMIZE.cb CUSTOMIZE.vars \
			ChangeLog INSTALL NEWS README TROUBLESHOOTING

EXAMPLEFILES=		gnatsweb-site-example.pl

do-install:
	@${MKDIR} ${PREFIX}/etc/gnatsweb
	@${INSTALL_DATA} ${WRKSRC}/gnatsweb-site.pl \
		${PREFIX}/etc/gnatsweb/gnatsweb-site.pl.default
	@[ -f ${PREFIX}/etc/gnatsweb/gnatsweb-site.pl ] || \
		${INSTALL_DATA} ${WRKSRC}/gnatsweb-site.pl \
		${PREFIX}/etc/gnatsweb
	@${MKDIR} ${CGI_DIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/gnatsweb.pl ${CGI_DIR}
	@${LN} -s ${PREFIX}/etc/gnatsweb/gnatsweb-site.pl ${CGI_DIR}
	@${INSTALL_DATA} ${WRKSRC}/gnatsweb.html ${CGI_DIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for doc in ${DOCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${DOCSDIR}; \
	done
	@${MKDIR} ${EXAMPLESDIR}
	@for example in ${EXAMPLEFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${example} ${EXAMPLESDIR}; \
	done
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm
.endif

.include <bsd.port.post.mk>
