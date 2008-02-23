# New ports collection makefile for:	p5-File-Fetch
# Date created:				31 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Fetch
PORTVERSION=	0.14
CATEGORIES=	ftp www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A generic file fetching mechanism

RUN_DEPENDS=	${SITE_PERL}/IPC/Cmd.pm:${PORTSDIR}/devel/p5-IPC-Cmd \
		${SITE_PERL}/Locale/Maketext/Simple.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		${SITE_PERL}/Module/Load/Conditional.pm:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Params/Check.pm:${PORTSDIR}/devel/p5-Params-Check
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=	File::Fetch.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
