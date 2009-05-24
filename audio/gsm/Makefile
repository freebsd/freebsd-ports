# New ports collection makefile for:	gsm
# Date created:		5 January 1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	gsm
PORTVERSION=	1.0.13
CATEGORIES=	audio
MASTER_SITES=	http://user.cs.tu-berlin.de/~jutta/gsm/ \
		http://kbs.cs.tu-berlin.de/~jutta/gsm/ \
		ftp://ftp.dvo.ru/pub/Gentoo/distfiles/ \
		ftp://ftp.gbnet.net/pub/digium/telephony/gnophone/ \
		ftp://216.27.40.102/pub/gnophone/ \
		ftp://ftp.gin.cz/pub/mirrors/ftp.digium.com/pub/telephony/gnophone/ \
		ftp://ftp.ip.pt/.disk1/finkmirrors/distfiles/

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Audio converter and library for converting u-law to gsm encoding

WRKSRC=		${WRKDIR}/gsm-1.0-pl13

USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		toast.1
MAN3=		gsm.3 gsm_explode.3 gsm_option.3 gsm_print.3
MLINKS=		toast.1 untoast.1	toast.1 tcat.1

.include <bsd.port.mk>
