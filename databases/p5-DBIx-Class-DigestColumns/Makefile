# New ports collection makefile for:	DBIx-Class-DigestColumns
# Date created:		23 Aug 2006
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-DigestColumns
PORTVERSION=	0.06000
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatic digest columns

RUN_DEPENDS=	p5-DBIx-Class>=0.06002:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest>=1.11:${PORTSDIR}/security/p5-Digest
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.1+

MAN3=	DBIx::Class::DigestColumns.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^\s*build_requires/ .. /},$$/ or /^\s*recommends/ .. /},$$/ ' ${WRKSRC}/Build.PL

.include <bsd.port.mk>
