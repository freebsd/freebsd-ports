# New ports collection makefile for:	p5-App-GitHub
# Date created:		2010-11-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	App-GitHub
PORTVERSION=	1.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	App
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	GitHub Command Tools

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON-XS>=2.3:${PORTSDIR}/converters/p5-JSON-XS \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Net-GitHub>=0.12:${PORTSDIR}/net/p5-Net-GitHub
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		github.pl.1
MAN3=		App::GitHub.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-IPC-Cmd>=0:${PORTSDIR}/devel/p5-IPC-Cmd
.endif

.include <bsd.port.post.mk>
