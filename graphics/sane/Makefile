# New ports collection makefile for:	sane
# Version required:		1.0.1
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

DISTNAME=	sane-1.0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/  \
		ftp://ftp.lahn.de/pub/platforms/linux/libs/

MAINTAINER=	gary@hotlava.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

.include <bsd.port.pre.mk>

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
.if ${OSVERSION} < 300000
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		GTK_CONFIG="${GTK_CONFIG}"
.else
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lcam" \
		GTK_CONFIG="${GTK_CONFIG}"
.endif

MAN1=		scanimage.1 \
		xscanimage.1 \
		saned.1
MAN5=		sane-abaton.5 \
		sane-agfafocus.5 \
		sane-apple.5 \
		sane-dc25.5 \
		sane-dll.5 \
		sane-dmc.5 \
		sane-epson.5 \
		sane-hp.5 \
		sane-microtek.5 \
		sane-microtek2.5 \
		sane-mustek.5 \
		sane-net.5 \
		sane-pint.5 \
		sane-pnm.5 \
		sane-qcam.5 \
		sane-scsi.5 \
		sane-umax.5

pre-configure:
	@${ECHO} "*** Note: SANE can be built with an X scanner interface"
	@${ECHO} "*** (xscanimage) as well as a GIMP plug-in.  If you wish"
	@${ECHO} "*** to do this, hit Ctrl-C right now and build/install"
	@${ECHO} "*** the GIMP and GTK packages/ports."

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.post.mk>
