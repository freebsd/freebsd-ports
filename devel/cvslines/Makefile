# New ports collection makefile for: 	cvslines
# Version required:			1.6.7
# Date created:				24 Aug 1998
# Whom:					jkoshy
#
# $FreeBSD$
#

DISTNAME=	cvslines-1.6.7
CATEGORIES=	devel
MASTER_SITES=	http://www.netapp.com/technology/freeware/cvslines/ \
		http://freefall.freebsd.org/~jkoshy/PORTS/

MAINTAINER=	jkoshy@freebsd.org

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	cvslines.1

do-install:
	PREFIX=${PREFIX} ${PERL5} ${WRKSRC}/INSTALL ${WRKSRC}/CONFIG

.include <bsd.port.mk>
