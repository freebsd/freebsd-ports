# New ports collection makefile for:	p5-DNS-ZoneParse
# Date created:				15 July 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	DNS-ZoneParse
PORTVERSION=	0.92
CATEGORIES=	dns textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DNS
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Parse and manipulate DNS Zone Files

PERL_CONFIGURE=	yes

MAN3=		DNS::ZoneParse.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.if ${PERL_LEVEL} < 500600
IGNORE=		needs perl 5.6+ to work, install lang/perl5 or lang/perl5.8 and try again
.endif
.endif

.include <bsd.port.post.mk>
