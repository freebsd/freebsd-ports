# New ports collection makefile for:	devel/p5-CPAN-Mini
# Date created:				16 February 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CPAN-Mini
PORTVERSION=	1.111001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	CPAN::Mini - create a minimal mirror of CPAN

RUN_DEPENDS=	p5-File-HomeDir>=0.57:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-libwww>=5:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	minicpan.1
MAN3=	CPAN::Mini.3 CPAN::Mini::App.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
