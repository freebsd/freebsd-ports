# New ports collection makefile for:	xmms-kde
# Date created:			27 April 2001
# Whom:				Jan Jungnickel <jan@jungnickel.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-kde
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jan@jungnickel.com
COMMENT=	Integrates XMMS into the KDE3 Panel

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_KDELIBS_VER=3
WRKSRC=		${WRKDIR}/${DISTNAME:S/0.0/0/}
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-xmms-prefix=${X11BASE}
USE_GNOME=	gtk12

post-install:
	${LN} -sf ${PREFIX}/share/doc/HTML/en/xmms-kde/common \
		${LOCALBASE}/share/doc/HTML/en/common

.include <bsd.port.mk>
