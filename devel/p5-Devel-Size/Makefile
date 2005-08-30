# New ports collection makefile for:	Devel-Size
# Date created:	   16 Octobre 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	Devel-Size
PORTVERSION=	0.63
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl extension for finding the memory usage of Perl variables

PERL_CONFIGURE=	yes

MAN3=		Devel::Size.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Need perl 5.6.1, try installing lang/perl5
.endif

.include <bsd.port.post.mk>
