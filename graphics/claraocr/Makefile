# New ports collection makefile for:	claraocr
# Date created:				5 November 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	claraocr
PORTVERSION=	20031214
PORTREVISION=	3
CATEGORIES=	graphics accessibility
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=distfiles
DISTNAME=	clara-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optical character recognition (OCR) utility

RUN_DEPENDS=	pnmenlarge:${PORTSDIR}/graphics/netpbm

USE_XORG=	x11
USE_PERL5=	yes
MAKE_ENV=	MKDIR="${MKDIR}"
MAKE_JOBS_SAFE=	yes

MAN1=	clara-adv.1 clara-dev.1 clara.1 selthresh.1

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|g' \
		clara.pl mkdoc.pl selthresh

post-install:
	${INSTALL_DATA} ${WRKSRC}/selthresh.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
