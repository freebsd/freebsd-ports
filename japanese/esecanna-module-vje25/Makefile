# New ports collection Makefile for: esecanna module for VJE-Delta 2.5
# Version required:	0.13.0
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	esecanna-module-vje25_0.13.0
PKGNAME=	ja-esecanna-module-vje25-0.13.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.idaemons.org/ports/distfiles/ \
		http://esecanna.netfort.gr.jp/

MAINTAINER=	knu@idaemons.org

LIB_DEPENDS=	esecanna.1:${PORTSDIR}/japanese/esecanna

# VJE-Delta 2.5 is installed under /usr/local fixedly
MAKE_ENV=	RCDIR="${PREFIX}/etc" VJECFGFILE="/usr/local/etc/vje/vje.cfg"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/esecanna/README.vje25.jp
.endif

.include <bsd.port.mk>
