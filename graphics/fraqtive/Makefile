# New ports collection makefile for:	fraqtive
# Date created:				Wed Sep  7 22:29:05 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fraqtive
PORTVERSION=	0.3.1
CATEGORIES=	graphics kde
MASTER_SITES=	http://zeus.polsl.gliwice.pl/%7Emimec/files/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Draws Mandelbrot and Julia fractals

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
