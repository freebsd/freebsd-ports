# New ports collection makefile for:	p5-Encode-HanConvert
# Date created:		15 April 2003
# Whom:	      		Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Encode-HanConvert
PORTVERSION=	0.31
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Encode
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@dragon2.net
COMMENT=	Traditional and Simplified Chinese mappings

PERL_CONFIGURE=	yes

MAN1=		b2g.pl.1 g2b.pl.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
MAN3=		Encode::HanConvert.3 Encode::HanConvert::Perl.3
PLIST_SUB+=	OLD="" NEW="@comment "
.else
PLIST_SUB+=	NEW="" OLD="@comment "
.endif

.include <bsd.port.post.mk>
