# Created by: mat
# $FreeBSD$

PORTNAME=	Data-Dump
PORTVERSION=	1.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pretty printing of data structures

USES=		perl5
USE_PERL5=	configure
NO_STAGE=	yes

MAN3=		Data::Dump.3 Data::Dump::Filtered.3 Data::Dump::Trace.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
