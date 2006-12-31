# New ports collection makefile for:	p5-Image-MetaData-GQview
# Date created:		2006-08-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Image-MetaData-GQview
PORTVERSION=	1.9
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl extension for GQview image metadata

PERL_CONFIGURE=	yes

MAN3=		Image::MetaData::GQview.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's,^use warnings;.*,,g' ${WRKSRC}/Makefile.PL \
		${WRKSRC}/lib/Image/MetaData/GQview.pm
.endif

.include <bsd.port.post.mk>
