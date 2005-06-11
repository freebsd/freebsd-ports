# New ports collection makefile for:	p5-Devel-PPPort
# Date created:				8 Aug 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	Devel-PPPort
PORTVERSION=	3.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Devel
PKGNAMEPREFIX=	p5-
#DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/_\1/}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl/Pollution/Portability

PERL_CONFIGURE=	yes

MAN3=		Devel::PPPort.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README HACKERS TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
