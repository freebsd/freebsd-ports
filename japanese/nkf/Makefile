# New ports collection makefile for:	nkf
# Date created:		5 February 1995
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	nkf
PORTVERSION=	1.71
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.ie.u-ryukyu.ac.jp/pub/software/kono/ \
		ftp://ftp.win.ne.jp/pub/misc/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/tools/code-conv/nkf/
EXTRACT_SUFX=	.shar
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	max@FreeBSD.org

EXTRACT_CMD=	${SH}
EXTRACT_BEFORE_ARGS=	# Empty
EXTRACT_AFTER_ARGS=	> /dev/null

NO_WRKSUBDIR=	yes
MAN1=		nkf.1 ../ja/man1/nkf.1
ALL_TARGET=	nkf

.include <bsd.port.mk>
