# Created by: mat
# $FreeBSD$

PORTNAME=	Alzabo-GUI-Mason
PORTVERSION=	0.12.01
DISTVERSION=	${PORTVERSION:C/\.(..)$/\1/}
CATEGORIES=	devel databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GUI for Alzabo using Mason

BUILD_DEPENDS=	p5-Alzabo>=0:${PORTSDIR}/devel/p5-Alzabo \
		p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
		p5-HTTP-BrowserDetect>=0:${PORTSDIR}/www/p5-HTTP-BrowserDetect
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
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

.include <bsd.port.mk>
