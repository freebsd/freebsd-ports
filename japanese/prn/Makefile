# New ports collection makefile for:	prn
# Date created:		19 Jun 1997
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	prn
PORTVERSION=	1.0
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
DISTNAME=	${PORTNAME}

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	A yet another converter from text file to postscript (with Japanese support)

RUN_DEPENDS=	kcc:${PORTSDIR}/japanese/kcc

INSTALL_TARGET=	install install.man
MANLANG=	ja
MAN1=		prn.1 cprn.1 cmt.1 psconv.1
MAN5=		cmtdefs.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
