# New ports collection makefile for:	p5-kakasi
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Kakasi
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	japanese textproc perl5
MASTER_SITES=	http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Kakasi library module for Perl5

LIB_DEPENDS=	kakasi.3:${PORTSDIR}/japanese/kakasi

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}"
MAN3=		Text::Kakasi.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
