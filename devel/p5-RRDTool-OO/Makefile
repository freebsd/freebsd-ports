# Created by: Stefan Pauly <stefan@fh-mainz.de>
# $FreeBSD$

PORTNAME=	RRDTool-OO
PORTVERSION=	0.32
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	stefan@fh-mainz.de
COMMENT=	RRDTool::OO - Object-oriented interface to RRDTool

BUILD_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool \
		p5-Log-Log4perl>=0.40:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		RRDTool::OO.3

.include <bsd.port.mk>
