# Created by: andreas@marvin.robin.de
# $FreeBSD$

PORTNAME=	xmandel
PORTVERSION=	1.0
PORTREVISION=	2
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
USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xt
USE_PERL5_BUILD=yes
NO_WRKSUBDIR=	yes
MAN1=		xmandel.1
PLIST_FILES=	bin/xmandel

pre-patch:
	@${PERL} -pi.orig -e 's|malloc.h|stdlib.h|' ${WRKSRC}/mandel.c

.include <bsd.port.mk>
