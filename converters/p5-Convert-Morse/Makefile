# New ports collection makefile for:	Convert-Morse
# Date created:				Wed Jan  3 16:37:55 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Convert-Morse
PORTVERSION=	0.04
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to convert between ASCII and Morse codes

PERL_CONFIGURE=	yes

MAN3=		Convert::Morse.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e '$$_ = "" if /require  5.6.0;/' ${WRKSRC}/lib/Convert/Morse.pm
.endif

.include <bsd.port.post.mk>
