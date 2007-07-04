# New ports collection makefile for:	xmms-kde
# Date created:			27 April 2001
# Whom:				Jan Jungnickel <jan@jungnickel.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-kde
PORTVERSION=	3.1
PORTREVISION=	6
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrates XMMS into the KDE3 Panel

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_KDELIBS_VER=3
WRKSRC=		${WRKDIR}/${DISTNAME:S/0.0/0/}
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-xmms-prefix=${X11BASE}
USE_GNOME=	gtk12

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

.include <bsd.port.post.mk>
