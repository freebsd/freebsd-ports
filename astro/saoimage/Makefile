# New ports collection makefile for:	saoimage
# Date created:		21 Feb 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	saoimage
PORTVERSION=	1.26.10
CATEGORIES=	astro
MASTER_SITES=	ftp://cfa-ftp.harvard.edu/pub/gsc/SAOimage/

MAINTAINER=	ports@FreeBSD.org

MAKEFILE=	makefile
ALL_TARGET=	${OPSYS}
USE_X_PREFIX=	yes
MAN1=		saoimage.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/saoimage ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/imtoolrc ${PREFIX}/etc/imtoolrc.sample
	${INSTALL_MAN} ${WRKSRC}/doc/saoimage.man ${PREFIX}/man/man1/saoimage.1

.include <bsd.port.mk>
