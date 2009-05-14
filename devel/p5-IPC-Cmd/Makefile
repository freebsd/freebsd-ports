# New ports collection makefile for:	devel/p5-IPC-Cmd
# Date created:				16 February 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-Cmd
PORTVERSION=	0.44
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Finding and running system commands made easy

PERL_CONFIGURE=	yes

MAN3=	IPC::Cmd.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500905
RUN_DEPENDS+=	p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Module-Load-Conditional>=0:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Params-Check>=0.20:${PORTSDIR}/devel/p5-Params-Check
.endif

.include <bsd.port.post.mk>
