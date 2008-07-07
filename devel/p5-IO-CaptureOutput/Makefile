# New ports collection makefile for:	devel/p5-IO-CaptureOutput
# Date created:				27 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-CaptureOutput
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Capture STDOUT/STDERR from subprocesses and XS/C modules

PERL_CONFIGURE=	yes

RUN_DEPENDS=	p5-PathTools>=3.27:${PORTSDIR}/devel/p5-PathTools
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=	IO::CaptureOutput.3

.include <bsd.port.mk>
