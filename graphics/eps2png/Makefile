# New ports collection makefile for:	eps2png
# Date created:				12 February 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	eps2png
PORTVERSION=	2.7
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JV

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Converts EPS images to PNG

USE_GHOSTSCRIPT=	yes
PERL_CONFIGURE=	yes
MAKE_ARGS=	INSTLLSCRIPT="${PREFIX}/bin"

MAN1=		eps2png.1

.include <bsd.port.mk>
