# New ports collection Makefile for: esecanna module for VJE-Delta 2.5
# Version required:	0.14.3
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	esecanna-module-vje25_0.14.3
PKGNAME=	ja-esecanna-module-vje25-0.14.3
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		http://people.FreeBSD.org/~knu/ports/distfiles/

MAINTAINER=	knu@idaemons.org

RUN_DEPENDS=	${PREFIX}/sbin/esecannaserver:${PORTSDIR}/japanese/esecanna

USE_AUTOCONF=	yes
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
