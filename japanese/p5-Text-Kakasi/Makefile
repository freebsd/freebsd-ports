# New ports collection makefile for:	p5-kakasi
# Date created:		25 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Kakasi
PORTVERSION=	1.04
CATEGORIES=	japanese perl5
MASTER_SITES=	http://www.daionet.gr.jp/~knok/kakasi/

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	kakasi.2:${PORTSDIR}/japanese/kakasi

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}"
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Text::Kakasi.3

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

.include <bsd.port.post.mk>
