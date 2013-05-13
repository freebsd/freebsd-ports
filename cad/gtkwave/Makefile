# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkwave
PORTVERSION=	3.3.46
CATEGORIES=	cad
MASTER_SITES=	http://gtkwave.sourceforge.net/
DISTNAME=	gtkwave-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Electronic Waveform Viewer

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 desktopfileutils
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	TCL GCONF
TCL_DESC=	Enable support for TCL/TK

PORTDOCS=	gtkwave.odt

.include	<bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCL}
USE_TCL=	84+
USE_TK=		84+
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
			--with-tk=${TK_LIBDIR}
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if ${PORT_OPTIONS:MGCONF}
CONFIGURE_ARGS+=	--with-gconf
USE_GNOME+=	gconf2
.endif

MAN1=	ghwdump.1 gtkwave.1 evcd2vcd.1 fst2vcd.1 fstminer.1 lxt2miner.1 \
	lxt2vcd.1 rtlbrowse.1 shmidcat.1 twinwave.1 vcd2fst.1 \
	vcd2lxt.1 vcd2lxt2.1 vcd2vzt.1 vermin.1 vzt2vcd.1 vztminer.1
MAN5=	gtkwaverc.5

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
