# New ports collection makefile for:	xpm
# Version required:     3.4k
# Date created:		14 September 1994
# Whom:			jkh
#
# $FreeBSD$
#

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

MAINTAINER=	jseger@FreeBSD.org

USE_IMAKE=	yes

MAN1=		cxpm.1 sxpm.1

.include <bsd.port.pre.mk>

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libXpm.so.4.11 ${PREFIX}/lib/libXpm.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@ranlib ${PREFIX}/lib/libXpm.a

.include <bsd.port.post.mk>
