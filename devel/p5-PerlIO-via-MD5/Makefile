# New ports collection makefile for:	devel/p5-PerlIO-via-MD5
# Date created:				22 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PerlIO-via-MD5
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	PerlIO
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	PerlIO layer for creating an MD5 digest of a file

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	PerlIO::via::MD5.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=		requires PerlIO, which was introduced in Perl 5.8.0. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
