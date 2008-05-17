# Ports collection makefile for:	gtkwave
# Date created:			April 28, 2008
# Whom:				bms
#
# $FreeBSD$
#

PORTNAME=	gtkwave3
PORTVERSION=	3.1.10
CATEGORIES=	cad
MASTER_SITES=	http://home.nc.rr.com/gtkwave/
DISTNAME=	gtkwave-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Electronic Waveform Viewer

CONFLICTS=	gtkwave-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

PLIST_FILES=	bin/ghwdump bin/gtkwave bin/lxt2miner bin/lxt2vcd \
		bin/mvl2lxt bin/mvl2vcd bin/rtlbrowse bin/shmidcat \
		bin/tex2vcd bin/tla2vcd bin/twinwave bin/vcd2lxt \
		bin/vcd2lxt2 bin/vcd2vzt bin/vermin bin/vzt2vcd \
		bin/vztminer

PORTDOCS=	gtkwave.odt
PORTEXAMPLES=	des.sav des.script des.v des.vzt

MAN1=	ghwdump.1 gtkwave.1 lxt2miner.1 lxt2vcd.1 mvl2lxt.1 \
	mvl2vcd.1 rtlbrowse.1 shmidcat.1 tex2vcd.1 tla2vcd.1 \
	twinwave.1 vcd2lxt.1 vcd2lxt2.1 vcd2vzt.1 vermin.1 \
	vzt2vcd.1 vztminer.1
MAN5=	gtkwaverc.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not compile on 5.x
.endif

.include <bsd.port.post.mk>
