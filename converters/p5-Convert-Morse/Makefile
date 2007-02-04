# New ports collection makefile for:	Convert-Morse
# Date created:				Wed Jan  3 16:37:55 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Convert-Morse
PORTVERSION=	0.05
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to convert between ASCII and Morse codes

PERL_CONFIGURE=	yes

MAN3=		Convert::Morse.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
IGNORE=		this program only support perl 5.8.1 or above
.endif

.include <bsd.port.post.mk>
