# New ports collection makefile for:	eps2png
# Date created:				12 February 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	eps2png
PORTVERSION=	1.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/Johan_Vromans

MAINTAINER=	nik@freebsd.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript6

USE_PERL5=	yes
PERL_CONFIGURE=	yes

do-install:
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/script/${PORTNAME} ${PREFIX}/bin


.include <bsd.port.mk>
