# New ports collection makefile for:	fpx
# Date created:				Jan 10 2001
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libfpx
PORTVERSION=	1.2.0.12
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Library routines for working with Flashpix images

MAKE_ARGS+=	-j2
USE_BZIP2=	yes

post-patch:
	${RM} ${WRKSRC}/ri_image/wchar.c

USE_LDCONFIG=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd

.include <bsd.port.mk>
