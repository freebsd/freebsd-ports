# New ports collection Makefile for: esecanna module for VJE-Delta 3.0
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	esecanna-module-vje30
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Esecanna module for VJE-Delta 3.0

RUN_DEPENDS=	${LOCALBASE}/sbin/esecannaserver:${PORTSDIR}/japanese/esecanna

USE_PERL5=	yes
USE_REINPLACE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
# VJE-Delta 3.0 is installed under /usr/local fixedly
CONFIGURE_ARGS=	--with-vjecfgfile="/usr/local/etc/vje30/vje.cfg"

DIST_SUBDIR=    esecanna

post-patch:
	${REINPLACE_CMD} -e " \
		s,!!PREFIX!!,${PREFIX},g; \
		" \
		${WRKSRC}/README.jp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
.for i in README CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i}.jp ${PREFIX}/share/doc/esecanna/${i}.vje30.jp
.endfor
.endif

.include <bsd.port.mk>
