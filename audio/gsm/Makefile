# New ports collection makefile for:	gsm
# Version required:     gsm-1.0.10
# Date created:		5 January 1995
# Whom:			pst
#
# $Id: Makefile,v 1.7 1996/11/15 23:13:44 obrien Exp $
#

DISTNAME=       gsm-1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	pst@FreeBSD.org

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10
MAN1=		toast.1
MAN3=		gsm.3 gsm_explode.3 gsm_option.3 gsm_print.3

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
