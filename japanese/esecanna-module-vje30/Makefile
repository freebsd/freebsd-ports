# New ports collection Makefile for: esecanna module for VJE-Delta 3.0
# Version required:	0.13.0
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	esecanna-module-vje30_0.13.0
PKGNAME=	ja-esecanna-module-vje30-0.13.0
CATEGORIES=	japanese
MASTER_SITES=	http://people.FreeBSD.org/~knu/ports/distfiles/ \
		http://esecanna.netfort.gr.jp/

MAINTAINER=	knu@idaemons.org

LIB_DEPENDS=	esecanna.1:${PORTSDIR}/japanese/esecanna

# VJE-Delta 3.0 is installed under /usr/local fixedly
MAKE_ENV=	RCDIR="${PREFIX}/etc" VJECFGFILE="/usr/local/etc/vje30/vje.cfg"

do-configure:
	@cd ${WRKSRC} && perl -i -pe " \
		s,!!PREFIX!!,${PREFIX},g; \
		" \
		README.jp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
	${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/share/doc/esecanna/README.vje30.jp
.endif

.include <bsd.port.mk>
