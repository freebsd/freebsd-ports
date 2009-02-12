# New ports collection makefile for:	p5-DNS-ZoneParse
# Date created:				15 July 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	DNS-ZoneParse
PORTVERSION=	0.96
CATEGORIES=	dns textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Parse and manipulate DNS Zone Files

PERL_CONFIGURE=	yes

MAN3=		DNS::ZoneParse.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
