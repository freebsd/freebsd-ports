# ex:ts=8
# Ports collection makefile for:	Text::Greeking::zh_TW
# Date created:			Jul 31, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Text-Greeking-zh_TW
PORTVERSION=	1.0
CATEGORIES=	chinese textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate meaningless Chinese text that creates the illusion of the document

RUN_DEPENDS=	p5-common-sense>=2.02:${PORTSDIR}/devel/p5-common-sense
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Text::Greeking::zh_TW.3

.include <bsd.port.mk>
