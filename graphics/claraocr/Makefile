# New ports collection makefile for:	claraocr
# Date created:				5 November 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	claraocr
PORTVERSION=	0.9.9
PORTREVISION?=	1
CATEGORIES=	graphics accessibility
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTNAME=	clara-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optical character recognition (OCR) utility

RUN_DEPENDS=	pnmenlarge:${PORTSDIR}/graphics/netpbm

USE_XLIB=	yes
USE_PERL5=	yes
MAKE_ENV=	MKDIR="${MKDIR}"

MAN1=	clara-adv.1 clara-dev.1 clara.1

post-patch:
.for file in clara.pl mkdoc.pl selthresh.pl
	@${PERL} -pi -e 's|^#!/usr/bin/perl|#!${PERL}|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
