# New ports collection makefile for:	p5-Alzabo-GUI-Mason
# Date created:				13 Oct 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	Alzabo-GUI-Mason
PORTVERSION=	0.1
CATEGORIES=	devel databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Alzabo
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A GUI for Alzabo using Mason

BUILD_DEPENDS=	${SITE_PERL}/Alzabo.pm:${PORTSDIR}/devel/p5-Alzabo \
		${SITE_PERL}/HTML/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/HTTP/BrowserDetect.pm:${PORTSDIR}/www/p5-HTTP-BrowserDetect
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes
CONFIGURE_ENV=	DATADIR=${DATADIR}
MAKE_ENV=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

MAN3=		Alzabo::GUI::Mason.3 Alzabo::GUI::Mason::Config.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

pre-install:
	@${MKDIR} ${DATADIR}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Needs perl 5.6+, install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
