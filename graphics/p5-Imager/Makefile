# ex:ts=8
# New ports collection makefile for:	p5-Imager
# Date created:			Jul 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Imager
PORTVERSION=	0.51
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.eecs.umich.edu/~addi/perl/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A Perl module for manipulating gray, color and rgba format images

LIB_DEPENDS=	\
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		t1:${PORTSDIR}/devel/t1lib \
		tiff:${PORTSDIR}/graphics/tiff \
		ungif:${PORTSDIR}/graphics/libungif

USE_FREETYPE=	yes
PERL_CONFIGURE=	yes
CONFIGURE_ENV=	IM_LIBPATH="${LOCALBASE}/lib" \
		IM_CFLAGS="${CFLAGS}" \
		IM_INCPATH="${LOCALBASE}/include/freetype1/freetype"

.include "Makefile.man"

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
