# New ports collection makefile for:	saoimage
# Date created:		21 Feb 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	saoimage
PORTVERSION=	1.35.1
CATEGORIES=	astro
MASTER_SITES=	http://tdc-www.harvard.edu/software/saoimage/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smithsonian Astrophysical Observatory image utility for X

USE_X_PREFIX=	yes
MAKEFILE=	makefile
MAKE_ENV=	OFLAGS="${CFLAGS}"
ALL_TARGET=	${OPSYS}

MAN1=		saoimage.1

PLIST_FILES=	bin/saoimage etc/imtoolrc.sample

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/saoimage ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/imtoolrc ${PREFIX}/etc/imtoolrc.sample
	${INSTALL_MAN} ${WRKSRC}/doc/saoimage.man ${PREFIX}/man/man1/saoimage.1

.include <bsd.port.mk>
