# New ports collection makefile for:   efax-gtk
# Whom:                                Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# Date Created:                        2004-02-29 10:33:43
#
# ex:ts=20:sw=20
#
# $FreeBSD$
#

PORTNAME=	efax-gtk
PORTVERSION=	2.2.9
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	jb.quenot@caraldi.com
COMMENT=	GUI front end for the efax fax program

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12
LIB_DEPENDS+=	gtkmm-2.0.6:${PORTSDIR}/x11-toolkits/gtk--2
RUN_DEPENDS=	${X11BASE}/bin/ggv:${PORTSDIR}/print/ggv2
RUN_DEPENDS+=	${LOCALBASE}/bin/gs:${PORTSDIR}/print/ghostscript-gnu

USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/gnome
MAN1=	efax.1 efix.1 efax-gtk.1

.include <bsd.port.pre.mk>

post-install:
	@${ECHO}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO}

.include <bsd.port.post.mk>
