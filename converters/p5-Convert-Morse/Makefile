# New ports collection makefile for:	Convert-Morse
# Date created:				Wed Jan  3 16:37:55 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Convert-Morse
PORTVERSION=	0.03
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Perl module to convert between ASCII and Morse codes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500007
#BROKEN=		"Requires perl 5.6.0"
.endif

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Convert::Morse.3

.include <bsd.port.post.mk>
