# New ports collection makefile for:	p5-File-HStore
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	File-HStore
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Store files on a filesystem using a very simple hash-based storage

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA.pm:${PORTSDIR}/security/p5-Digest-SHA

PERL_CONFIGURE=	yes

MAN3=		File::HStore.3

post-patch:
		@${RM} ${WRKSRC}/lib/File/HStore.pm.orig

.include <bsd.port.mk>
