# New ports collection makefile for:    p5-MIME-Base64
# Date created:                         June 21th 1997
# Whom:                                 ache@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	MIME-Base64
PORTVERSION=	3.01
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MIME
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl5 module for Base64 and Quoted-Printable encodings

PERL_CONFIGURE=	YES
CONFIGURE_ARGS=	INSTALLDIRS=site

MAN3=		MIME::Base64.3 \
		MIME::QuotedPrint.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 500804
IGNORE=		This port is needed only for perls below 5.8.4
.endif

.include <bsd.port.post.mk>
