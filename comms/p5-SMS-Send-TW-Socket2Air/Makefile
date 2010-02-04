# New ports collection makefile for:	p5-SMS-Send-TW-Socket2Air
# Date created:		2010-01-21
# Whom:			Jui-Nan Lin <jnlin@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	SMS-Send-TW-Socket2Air
PORTVERSION=	0.01
CATEGORIES=	comms perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	SMS::Send driver for Socket2Air

RUN_DEPENDS=	p5-SMS-Send>=0:${PORTSDIR}/comms/p5-SMS-Send \
  		p5-Switch>=0:${PORTSDIR}/lang/p5-Switch \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Text-Iconv>=0:${PORTSDIR}/converters/p5-Text-Iconv
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SMS::Send::TW::Socket2Air.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
IGNORE=		perl 5.10 or above is required
.endif

.include <bsd.port.post.mk>
