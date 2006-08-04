# New ports collection makefile for:	p5-Linux-Pid
# Date created:		1 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Linux-Pid
DISTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Get native PID and the PPID

BUILD_DEPENDS=	p5-Inline>=0.44:${PORTSDIR}/devel/p5-Inline
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Linux::Pid.3

.include <bsd.port.mk>
