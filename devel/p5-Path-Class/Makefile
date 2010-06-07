# New ports collection makefile for:	Path::Class
# Date created:		2004-07-25
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Path-Class
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/K/KW/KWILLIAMS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cross-platform path specification manipulation

PERL_MODBUILD=	yes

MAN3=		Path::Class.3 \
		Path::Class::File.3 \
		Path::Class::Dir.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
