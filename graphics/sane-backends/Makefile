# New ports collection makefile for:	sane-backends
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane-backends
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/ \
		ftp://ftp.de.mostang.com/pub/sane/ \
		ftp://ftp.no.mostang.com/pub/sane/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	saned.1 scanimage.1
MAN5=	sane-abaton.5 sane-agfafocus.5 sane-apple.5 sane-artec.5 \
	sane-as6e.5 sane-avision.5 sane-canon.5 sane-coolscan.5 \
	sane-dc210.5 sane-dc25.5 sane-dll.5 sane-dmc.5 sane-epson.5 \
	sane-fujitsu.5 sane-hp.5 sane-microtek.5 sane-microtek2.5 \
	sane-mustek.5 sane-mustek_pp.5 sane-nec.5 sane-net.5 sane-pie.5 \
	sane-pint.5 sane-plustek.5 sane-pnm.5 sane-qcam.5 sane-ricoh.5 \
	sane-s9036.5 sane-scsi.5 sane-sharp.5 sane-snapscan.5 \
	sane-st400.5 sane-tamarack.5 sane-umax.5 sane-v4l.5

.include <bsd.port.mk>
