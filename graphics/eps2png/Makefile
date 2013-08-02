# Created by: nik
# $FreeBSD$

PORTNAME=	eps2png
PORTVERSION=	2.7
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JV

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Converts EPS images to PNG

USE_GHOSTSCRIPT=	yes
USES=		perl5
USE_PERL5=	configure
MAKE_ARGS=	INSTLLSCRIPT="${PREFIX}/bin"

MAN1=		eps2png.1

.include <bsd.port.mk>
