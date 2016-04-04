# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	oicq
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	chinese net
MASTER_SITES=	SF/perl-${PORTNAME}/perl-${PORTNAME}/Net-OICQ-${PORTVERSION}
DISTNAME=	Net-OICQ-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implements OICQ messaging protocol

BUILD_DEPENDS=	p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Crypt-OICQ>=0:security/p5-Crypt-OICQ

USES=		perl5
USE_PERL5=	configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qq ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/demo1 ${STAGEDIR}${PREFIX}/bin/qq-demo1

.include <bsd.port.mk>
