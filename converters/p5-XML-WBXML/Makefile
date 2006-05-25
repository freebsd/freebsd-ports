# New ports collection makefile for:	p5-XML-WBXML
# Date created:				25 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-WBXML
PORTVERSION=	0.02
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Convert between XML and WBXML using libwbxml2

LIB_DEPENDS=	wbxml2:${PORTSDIR}/textproc/wbxml2

MAN3=	XML::WBXML.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	currently requires Perl 5.8.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
