# New ports collection makefile for:   wenju
# Date created:                18 Oct 2003
# Whom:                        Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	wenju
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wenju

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of writing tools in Chinese

USE_GNOME=	gtk20
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=	yes
USE_LIBTOOL=	yes

post-install:
		gtk-query-immodules-2.0 > ${PREFIX}/etc/gtk-2.0/gtk.immodules

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500041
PATCHFILES+=	configure-getopt.patch
.endif

.include <bsd.port.post.mk>
