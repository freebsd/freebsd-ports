# New ports collection makefile for: kcc
# Date created:		26 May 1997
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kcc
PORTVERSION=	1.0
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_PORTS_JP}
DISTNAME=	${PORTNAME}

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	Kanji code conversion Filter

INSTALL_TARGET=	install install.man
MANLANG=	ja
MAN1=		kcc.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
