# New ports collection makefile for:	claraocr
# Date created:				5 November 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	claraocr
PORTVERSION=	20031214
PORTREVISION=	1
CATEGORIES=	graphics accessibility
MASTER_SITES=	http://www.geocities.com/claraocr/
DISTNAME=	clara-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optical character recognition (OCR) utility

RUN_DEPENDS=	pnmenlarge:${PORTSDIR}/graphics/netpbm

USE_XORG=	x11
USE_PERL5=	yes
MAKE_ENV=	MKDIR="${MKDIR}"
MAKE_ARGS=	-j`${SYSCTL} -n hw.ncpu`

MAN1=	clara-adv.1 clara-dev.1 clara.1

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|g' \
		clara.pl mkdoc.pl selthresh

.include <bsd.port.mk>
