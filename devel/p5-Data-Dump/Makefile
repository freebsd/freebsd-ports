# New ports collection makefile for:	p5-Data-Dump
# Date created:	   23 March 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Data-Dump
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Pretty printing of data structures

PERL_CONFIGURE=	yes

MAN3=		Data::Dump.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE="Need at least perl 5.6 to build"
.endif

.include <bsd.port.post.mk>
