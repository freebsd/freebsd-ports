# New ports collection makefile for:	xpm
# Version required:     3.4k
# Date created:		14 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.21 1998/11/11 05:37:23 asami Exp $
#

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

MAINTAINER=	jseger@FreeBSD.org

USE_IMAKE=	yes

MAN1=		cxpm.1 sxpm.1
NOMANCOMPRESS=	yes

.include <bsd.port.pre.mk>

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libXpm.so.4.11 ${PREFIX}/lib/libXpm.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
