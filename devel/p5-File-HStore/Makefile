# New ports collection makefile for:	p5-File-HStore
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	File-HStore
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AD/ADULAU
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Store files on a filesystem using a very simple hash-based storage

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA2.pm:${PORTSDIR}/security/p5-Digest-SHA2

PERL_CONFIGURE=	yes

MAN3=		File::HStore.3

.include <bsd.port.mk>
