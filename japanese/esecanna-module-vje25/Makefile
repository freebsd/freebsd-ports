# New ports collection Makefile for: esecanna module for VJE-Delta 2.5
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	esecanna-module-vje25
PORTVERSION=	0.14.6
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Esecanna module for VJE-Delta 2.5

RUN_DEPENDS=	${LOCALBASE}/sbin/esecannaserver:${PORTSDIR}/japanese/esecanna

USE_AUTOCONF_VER=	213
USE_GMAKE=	yes

DIST_SUBDIR=    esecanna

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
.for i in README CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i}.jp ${PREFIX}/share/doc/esecanna/${i}.vje25.jp
.endfor
.endif

.include <bsd.port.mk>
