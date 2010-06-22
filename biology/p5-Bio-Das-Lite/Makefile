# New ports collection makefile for:	p5-Bio-Das-Lite
# Date created:				26 Feb, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Bio-Das-Lite
PORTVERSION=	2.04
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the DAS (HTTP+XML) Protocol

BUILDS_DEPENDS=	p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite \
		p5-WWW-Curl>=4.07:${PORTSDIR}/www/p5-WWW-Curl
RUN_DEPENDS=	${BUILDS_DEPENDS}

PERL_MODBUILD=	YES

MAN3=	Bio::Das::Lite.3

.include <bsd.port.mk>
