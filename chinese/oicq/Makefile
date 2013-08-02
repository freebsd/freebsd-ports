# New ports collection makefile for:	zh-oicq
# Date created:		10 Nov 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	oicq
PORTVERSION=	1.6
CATEGORIES=	chinese net
MASTER_SITES=	SF/perl-${PORTNAME}/perl-${PORTNAME}/Net-OICQ-${PORTVERSION}
DISTNAME=	Net-OICQ-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implements OICQ messaging protocol

BUILD_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Crypt-OICQ>=0:${PORTSDIR}/security/p5-Crypt-OICQ

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::OICQ.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qq ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/demo1 ${PREFIX}/bin/qq-demo1

.include <bsd.port.mk>
