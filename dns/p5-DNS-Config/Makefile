# New ports collection makefile for:		p5-DNS-Config
# Date created:					22 February 2003
# Whom:	      					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	DNS-Config
PORTVERSION=	0.66
PORTREVISION=	0
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DNS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	DNS::Config is set of perl modules for name service configurations

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

DOCSDIR=	${PREFIX}/share/doc/p5-DNS-Zone
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
