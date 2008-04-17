# New ports collection makefile for:	devel/p5-IPC-Cmd
# Date created:				16 February 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-Cmd
PORTVERSION=	0.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	IPC::Cmd - finding and running system commands made easy

RUN_DEPENDS=	${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/Module/Load/Conditional.pm:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-IPC-Run>=0.55:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Params-Check>=0.20:${PORTSDIR}/devel/p5-Params-Check
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	IPC::Cmd.3

post-patch:
	${RM} -f ${WRKSRC}/lib/IPC/Cmd.pm.orig

.include <bsd.port.mk>
