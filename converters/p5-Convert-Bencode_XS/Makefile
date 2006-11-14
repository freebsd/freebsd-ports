# New ports collection makefile for:	p5-Convert-Bencode_XS
# Date created:		2006-08-23
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Convert-Bencode_XS
PORTVERSION=	0.06
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Faster conversions to/from Bencode format

RUN_DEPENDS=	${SITE_PERL}/Convert/Bencode.pm:${PORTSDIR}/converters/p5-Convert-Bencode

PERL_CONFIGURE=	yes

MAN3=		Convert::Bencode_XS.3

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/extras/* ${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
