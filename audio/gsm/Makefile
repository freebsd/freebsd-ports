# New ports collection makefile for:	gsm
# Date created:		5 January 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	gsm
PORTVERSION=	1.0.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/local/kbs/tubmik/gsm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio converter and library for converting u-law to gsm encoding

WRKSRC=		${WRKDIR}/gsm-1.0-pl10

INSTALLS_SHLIB=	yes

MAN1=		toast.1
MAN3=		gsm.3 gsm_explode.3 gsm_option.3 gsm_print.3
MLINKS=		toast.1 untoast.1	toast.1 tcat.1

.include <bsd.port.mk>
