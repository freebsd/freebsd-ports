# New ports collection makefile for:    xmandel
# Date created:         		18 October 1996
# Whom:                 		andreas@marvin.robin.de
#
# $FreeBSD$
#

PORTNAME=	xmandel
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cray.com/src/graphics/xmandel/
# The README says the location is ftp.cray.com:/usr/ftp/src/graphics/xmandel,
# but this has changed apparently.
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.shar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window based interface to Mandelbrot sets and Julia sets

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
USE_IMAKE=	yes
USE_PERL5_BUILD=yes
NO_WRKSUBDIR=	yes
MAN1=		xmandel.1
PLIST_FILES=	bin/xmandel

pre-patch:
	@${PERL} -pi.orig -e 's|malloc.h|stdlib.h|' ${WRKSRC}/mandel.c

.include <bsd.port.mk>
