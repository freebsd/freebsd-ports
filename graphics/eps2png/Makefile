# New ports collection makefile for:	eps2png
# Date created:				12 February 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	eps2png
PORTVERSION=	2.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/J/JV/JV/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts EPS images to PNG

USE_GHOSTSCRIPT_RUN=	yes

PERL_CONFIGURE=	yes

MAN1=		eps2png.1

do-install:
	@cd ${WRKSRC}; ${SETENV} ${INSTALL_ENV} ${MAKE} INSTALLSCRIPT=${PREFIX}/bin install

.include <bsd.port.mk>
