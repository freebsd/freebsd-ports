# New ports collection Makefile for: esecanna module for Wnn6
# Version required:	0.13.0
# Date created:		26 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	esecanna-module-wnn6_0.13.0
PKGNAME=	ja-esecanna-module-wnn6-0.13.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.idaemons.org/ports/distfiles/ \
		http://esecanna.netfort.gr.jp/

MAINTAINER=	knu@idaemons.org

LIB_DEPENDS=	esecanna.1:${PORTSDIR}/japanese/esecanna \
		wnn6.1:${PORTSDIR}/japanese/Wnn6-lib

MAKE_ENV=	RCDIR="${PREFIX}/etc"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/esecanna/README.wnn6.jp
.endif

.include <bsd.port.mk>
