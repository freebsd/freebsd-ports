# New ports collection makefile for:	xpm
# Version required:     3.4k
# Date created:		14 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.18 1998/09/21 21:28:17 steve Exp $
#

DISTNAME=       xpm-3.4k
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

MAINTAINER=	jseger@FreeBSD.org

USE_IMAKE=	yes

MAN1=		cxpm.1 sxpm.1

post-install:
	if [ "${PORTOBJFORMAT}" = "elf" ]; then \
		${LN} -sf libXpm.so.4.11 ${PREFIX}/lib/libXpm.so.4; \
	fi
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
