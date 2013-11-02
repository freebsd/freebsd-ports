# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBI
PORTVERSION=	1.630
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The perl5 Database Interface.  Required for DBD::* modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	PROXY DOCS
PROXY_DESC=	Build DBI::Proxy

CONFLICTS=	p5-DBI-1.3*

USES=		perl5 shebangfix
USE_PERL5=	configure

PORTDOCS=	Changes

SHEBANG_FILES=	dbixs_rev.pl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROXY}
BUILD_DEPENDS+=	p5-PlRPC>=0.2001:${PORTSDIR}/net/p5-PlRPC
RUN_DEPENDS+=	p5-PlRPC>=0.2001:${PORTSDIR}/net/p5-PlRPC
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
