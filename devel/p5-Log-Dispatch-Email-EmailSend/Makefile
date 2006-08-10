# New ports collection makefile for:	p5-Log-Dispatch-Email-EmailSend
# Date created:		2 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-Email-EmailSend
DISTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Subclass of Log-Dispatch-Email that uses Email-Send

BUILD_DEPENDS=	p5-Email-Send>=2.0:${PORTSDIR}/mail/p5-Email-Send \
		p5-Email-Simple-Creator>=0:${PORTSDIR}/mail/p5-Email-Simple-Creator \
		p5-Log-Dispatch>=2.0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	YES

MAN3=		${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
