# New ports collection makefile for:	claraocr
# Date created:				5 November 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	claraocr
PORTVERSION=	0.9.9
CATEGORIES=	graphics
MASTER_SITES=	ftp://carroll.cac.psu.edu/pub/linux/distributions/mandrake-devel/projects/claraocr/ \
		ftp://ftp.wtfo.com/pub/linux/Mandrake-devel/projects/claraocr/ \
		ftp://gd.tuwien.ac.at/pub/linux/Mandrake-devel/projects/claraocr/ \
		ftp://mandrake.redbox.cz/Mandrake-devel/projects/claraocr/ \
		ftp://ftp.proxad.net/pub/Distributions_Linux/Mandrake-devel/projects/claraocr/
DISTNAME=	clara-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Optical character recognition (OCR) utility

USE_XLIB=	yes
USE_PERL5=	yes
MAKE_ENV=	MKDIR="${MKDIR}"

MAN1=	clara-adv.1 clara-dev.1 clara.1

post-patch:
.for file in clara.pl mkdoc.pl selthresh.pl
	@${PERL} -pi -e 's|^#!/usr/bin/perl|#!${PERL}|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
