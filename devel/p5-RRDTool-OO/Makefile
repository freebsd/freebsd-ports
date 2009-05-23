# New ports collection makefile for:	RRDTool-OO
# Date created:		13 Feb 2006
# Whom:			Stefan Pauly <stefan@fh-mainz.de>
#
# $FreeBSD$
#

PORTNAME=	RRDTool-OO
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	stefan@fh-mainz.de
COMMENT=	RRDTool::OO - Object-oriented interface to RRDTool

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/RRDs.pm:${PORTSDIR}/databases/rrdtool\
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		RRDTool::OO.3

.include <bsd.port.mk>
