# New ports collection makefile for:	p5-Attribute-Persistent
# Date created:				5 Jan 2004
# Whom:					Mathieu Arnold <mat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		Attribute-Persistent
PORTVERSION=		1.1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Attribute
PKGNAMEPREFIX=		p5-

MAINTAINER=		mat@FreeBSD.org
COMMENT=		Attribute::Persistent - Really lazy persistence

BUILD_DEPENDS=		${SITE_PERL}/Attribute/Handlers/Prospective.pm:${PORTSDIR}/devel/p5-Attribute-Handlers-Prospective \
			${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
			${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM

PERL_CONFIGURE=		yes

MAN3=			Attribute::Persistent.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Need perl 5.6.1, try installing lang/perl5
.endif

.include <bsd.port.post.mk>
