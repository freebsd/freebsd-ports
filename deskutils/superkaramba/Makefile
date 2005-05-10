# New ports collection makefile for:	superkaramba
# Date created:			Sat Nov  8 20:23:31 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		superkaramba
PORTVERSION=		0.36
PORTREVISION=		1
CATEGORIES=		deskutils kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netdragon

MAINTAINER=		markus@FreeBSD.org
COMMENT=		KDE tool that allows interactive eye-candy on the desktop

EXTRA_PATCHES=		${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDEBASE_VER=	3
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNOME=		glib12 gtk12
USE_PYTHON=		yes
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes

CONFIGURE_ARGS+=	--with-pythondir=${PYTHON_INCLUDEDIR}

OPTIONS=	XMMS "XMMS support" off \
		XMBMON "Mainboard monitor support" on

.include <bsd.port.pre.mk>

.if defined(WITH_XMMS)
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
.endif

.if defined(WITH_XMBMON)
RUN_DEPENDS=	mbmon:${PORTSDIR}/sysutils/xmbmon
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g;' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
