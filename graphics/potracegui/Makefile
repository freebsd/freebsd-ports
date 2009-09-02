# New ports collection makefile for:	potracegui
# Date created:				Tue Jun 22 10:03:28 CEST 2004
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	potracegui
PORTVERSION=	1.3.4
PORTREVISION=	3
CATEGORIES=	graphics kde
MASTER_SITES=	SF

MAINTAINER=	markus@FreeBSD.org
COMMENT=	GUI for potrace, a program for tracing bitmap images

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-configure

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22

OPTIONS=	POTRACE "potrace backend" on \
		AUTOTRACE "Autotrace backend" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_POTRACE)
RUN_DEPENDS+=	potrace:${PORTSDIR}/graphics/potrace
.endif

.if !defined(WITHOUT_AUTOTRACE)
RUN_DEPENDS+=	autotrace:${PORTSDIR}/graphics/autotrace
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/config.h.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${TOUCH}
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
