# New ports collection makefile for:	gsm
# Version required:     gsm-1.0.10
# Date created:		5 January 1995
# Whom:			pst
#
# $FreeBSD$
#

DISTNAME=       gsm-1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10
MAN1=		toast.1
MAN3=		gsm.3 gsm_explode.3 gsm_option.3 gsm_print.3
MLINKS=		toast.1 untoast.1	toast.1 tcat.1

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
