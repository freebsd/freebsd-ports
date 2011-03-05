# New ports collection makefile for:	p5-Term-Menus
# Date created:		2006-08-01
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Term-Menus
PORTVERSION=	1.79
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/R/RE/REEDFISH/
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Create Powerful Terminal, Console and CMD Environment Menus

BUILD_DEPENDS=	p5-Data-Dump-Streamer>0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-Term-RawInput>=0:${PORTSDIR}/devel/p5-Term-RawInput \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Term::Menus.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Module-Load-Conditional>=0:${PORTSDIR}/devel/p5-Module-Load-Conditional
.endif

.include <bsd.port.post.mk>
