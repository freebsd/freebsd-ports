# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	A fast Console Chinese System which supports framebuffer device

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-included-gettext=${LOCALBASE}
USE_GMAKE=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS= # empty
USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		zhcon.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
