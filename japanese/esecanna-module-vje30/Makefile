# New ports collection Makefile for: esecanna module for VJE-Delta 3.0
# Version required:	0.14.3
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	esecanna-module-vje30_0.14.3
PKGNAME=	ja-esecanna-module-vje30-0.14.3
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		http://people.FreeBSD.org/~knu/ports/distfiles/

MAINTAINER=	knu@idaemons.org

RUN_DEPENDS=	${LOCALBASE}/sbin/esecannaserver:${PORTSDIR}/japanese/esecanna

USE_AUTOCONF=	yes
USE_GMAKE=	yes
# VJE-Delta 3.0 is installed under /usr/local fixedly
CONFIGURE_ARGS=	--with-vjecfgfile="/usr/local/etc/vje30/vje.cfg"

DIST_SUBDIR=    esecanna

post-patch:
	@cd ${WRKSRC} && perl -i -pe " \
		s,!!PREFIX!!,${PREFIX},g; \
		" \
		README.jp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
.for i in README CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i}.jp ${PREFIX}/share/doc/esecanna/${i}.vje30.jp
.endfor
.endif

.include <bsd.port.mk>
