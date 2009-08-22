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

MAINTAINER=	bg1tpt@gmail.com
COMMENT=	Implements OICQ messaging protocol

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Crypt/OICQ.pm:${PORTSDIR}/security/p5-Crypt-OICQ

PERL_CONFIGURE=	5.8.0+

MAN3=		Net::OICQ.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/qq ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/demo1 ${PREFIX}/bin/qq-demo1

.include <bsd.port.mk>
