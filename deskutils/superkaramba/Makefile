# New ports collection makefile for:	superkaramba
# Date created:			Sat Nov  8 20:23:31 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=		superkaramba
PORTVERSION=		0.33
PORTREVISION=		3
CATEGORIES=		deskutils kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netdragon

MAINTAINER=		brueffer@phoenix-systems.de
COMMENT=		KDE tool that allows interactive eye-candy on the desktop

.if defined(WITH_XMMS)
LIB_DEPENDS=		xmms.4:${PORTSDIR}/multimedia/xmms
.endif

.if defined(WITH_XMBMON)
RUN_DEPENDS=		mbmon:${PORTSDIR}/sysutils/xmbmon
.endif

USE_KDEBASE_VER=	3
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_GNOME=		glib12 gtk12
USE_PYTHON=		yes
PYTHON_VERSION=		python2.3
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes

CONFIGURE_ARGS+=	--with-pythondir=${PYTHON_INCLUDEDIR}

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

pre-everything::
.if !defined(WITH_XMMS)
	@${ECHO_MSG} "You can enable XMMS support by defining WITH_XMMS."
.endif
.if !defined(WITH_XMBMON)
	@${ECHO_MSG} "You can enable mainboard monitor support by defining WITH_XMBMON."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
