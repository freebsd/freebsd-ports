# New ports collection makefile for:	gsm
# Version required:     gsm-1.0.10
# Date created:		5 January 1995
# Whom:			pst
#
# $Id: Makefile,v 1.10 1997/07/17 15:12:39 max Exp $
#

DISTNAME=       gsm-1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=         ${WRKDIR}/gsm-1.0-pl10
MAN1=		toast.1
MAN3=		gsm.3 gsm_explode.3 gsm_option.3 gsm_print.3

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if defined(NOMANCOMPRESS)
	${LN} -sf ${PREFIX}/man/man1/toast.1 ${PREFIX}/man/man1/untoast.1
	${LN} -sf ${PREFIX}/man/man1/toast.1 ${PREFIX}/man/man1/tcat.1
.else
	${LN} -sf ${PREFIX}/man/man1/toast.1.gz ${PREFIX}/man/man1/untoast.1.gz
	${LN} -sf ${PREFIX}/man/man1/toast.1.gz ${PREFIX}/man/man1/tcat.1.gz
.endif

.include <bsd.port.mk>
