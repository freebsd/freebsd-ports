# New ports collection makefile for:	sane
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane
PORTVERSION=	1.0.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.mostang.com/pub/sane/
MASTER_SITE_SUBDIR=	apps/graphics/capture

MAINTAINER= 	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIBS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gtktest

MAN1=	saned.1 scanimage.1 xscanimage.1
MAN5=	sane-abaton.5 sane-agfafocus.5 sane-apple.5 sane-dll.5 sane-dc25.5 \
	sane-dmc.5 sane-epson.5 sane-hp.5 sane-microtek.5 sane-microtek2.5 \
	sane-mustek.5 sane-net.5 sane-pint.5 sane-pnm.5 sane-umax.5 \
	sane-qcam.5 sane-scsi.5 sane-artec.5 sane-fujitsu.5 sane-sharp.5

pre-configure:
	@${ECHO} "*** Note: SANE can be built with an X scanner interface"
	@${ECHO} "*** (xscanimage) as well as a GIMP plug-in.  If you wish"
	@${ECHO} "*** to do this, hit Ctrl-C right now and build/install"
	@${ECHO} "*** the GIMP and GTK packages/ports."

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
