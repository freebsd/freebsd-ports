# New ports collection makefile for:	prn
# Version required:	2.0
# Date created:		19 Jun 1997
# Whom:			Satoshi TAOKA <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.2 1997/09/14 21:35:46 max Exp $
#

DISTNAME=	prn
PKGNAME=	ja-prn-1.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.eos.hokudai.ac.jp/pub/tools/

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

RUN_DEPENDS=	kcc:${PORTSDIR}/japanese/kcc

INSTALL_TARGET=	install install.man
MANLANG=	ja
MAN1=		prn.1 cprn.1 cmt.1 psconv.1
MAN5=		cmtdefs.5

.include <bsd.port.mk>
