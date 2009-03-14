# New ports collection makefile for:	libisofs
# Date created:		2008 November 06
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	libisofs
PORTVERSION=	0.6.16
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	fbsd@opal.com
COMMENT=	Libburnia ISO9660 filesystem creation library

LIB_DEPENDS=	burn.4:${PORTSDIR}/devel/libburn

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib -liconv"

USE_ICONV=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-install:
		${MKDIR} ${PREFIX}/libdata/pkgconfig
		${MV} ${PREFIX}/lib/pkgconfig/${PORTNAME}-1.pc ${PREFIX}/libdata/pkgconfig/${PORTNAME}-1.pc
		${RMDIR} ${PREFIX}/lib/pkgconfig

.include <bsd.port.post.mk>
