# New ports collection makefile for:	p5-Net-DNS-Resolver-Programmable
# Date created:				February 9, 2007
# Whom:	      				Koen Martens <gmc@sonologic.nl>
#
# $FreeBSD$
#

PORTNAME=	Net-DNS-Resolver-Programmable
PORTVERSION=	0.002.2
CATEGORIES=	dns net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	gmc@sonologic.nl
COMMENT=	Programmable DNS resolver for off-line testing

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes
PERL_CONFIGURE=	yes

MAN3=		Net::DNS::Resolver::Programmable.3

.include <bsd.port.pre.mk>

DOCSDIR=	${PREFIX}/share/doc/p5-Net-DNS-Resolver-Programmable

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in CHANGES README TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
