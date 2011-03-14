# Ports collection makefile for:	Astro-FITS-CFITSIO
# Date created:				Jan 6, 2010
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Astro-FITS-CFITSIO
PORTVERSION=	1.06
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl extension for using the cfitsio library

LIB_DEPENDS=	cfitsio.0:${PORTSDIR}/astro/cfitsio

PERL_CONFIGURE=	yes

MAN3=	Astro::FITS::CFITSIO.3

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
