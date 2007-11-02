# New ports collection makefile for:	fpx
# Date created:				Jan 10 2001
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libfpx
PORTVERSION=	1.2.0.12
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt
PATCHFILES=	fpx.mega-patch.2007-11-01.bz2
PATCH_SITES=	http://aldan.algebra.com/~mi/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Library routines for working with Flashpix images

MAKE_ARGS+=	-j`${SYSCTL} -n hw.ncpu`
USE_BZIP2=	yes

post-patch:
	${RM} ${WRKSRC}/ri_image/wchar.c ${WRKSRC}/fpx/fpxlib.h

USE_LDCONFIG=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd

.include <bsd.port.mk>

# We want the port's Makefile to build compiler-flags from scratch
# (based on WARNS= in particular) instead of being influenced by
# the environment... There is no obvious way to prevent bsd.port.mk
# from adding CFLAGS and CXXFLAGS to the build environment, so we
# remove them here.
MAKE_ENV:=	${MAKE_ENV:NCFLAGS=*:NCXXFLAGS=*}
