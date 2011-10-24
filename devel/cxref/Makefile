# New ports collection makefile for:	cxref
# Date created:		23 October 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cxref
PORTVERSION=	1.6c
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-cxref/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C program cross-referencing & documentation tool

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-cxref-cpp
ALL_TARGET=	programs

MAN1=		cxref.1 cxref-query.1

post-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/*.pl ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/*.el ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/README* ${DATADIR}

.include <bsd.port.mk>
