# New ports collection Makefile for: esecanna module for Wnn6
# Date created:		26 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	esecanna-module-wnn6
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Esecanna module for Wnn6

LIB_DEPENDS=	wnn6.2:${PORTSDIR}/japanese/Wnn6-lib
RUN_DEPENDS=	${LOCALBASE}/sbin/esecannaserver:${PORTSDIR}/japanese/esecanna

USE_AUTOCONF=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${PREFIX}/include/wnn6" \
		LDFLAGS="${LDFLAGS} -L${PREFIX}/lib"

DIST_SUBDIR=    esecanna

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
.for i in README CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i}.jp ${PREFIX}/share/doc/esecanna/${i}.wnn6.jp
.endfor
.endif

.include <bsd.port.mk>
