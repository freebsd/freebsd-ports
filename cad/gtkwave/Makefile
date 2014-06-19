# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkwave
PORTVERSION=	3.3.60
CATEGORIES=	cad
MASTER_SITES=	http://gtkwave.sourceforge.net/
DISTNAME=	gtkwave-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Electronic Waveform Viewer

USES=		desktop-file-utils gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	TCL GCONF
TCL_DESC=	Enable support for TCL/TK
TCL_USES=	tk

PORTDOCS=	gtkwave.odt

.include	<bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCL}
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
			--with-tk=${TK_LIBDIR}
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if ${PORT_OPTIONS:MGCONF}
CONFIGURE_ARGS+=	--with-gconf
USE_GNOME+=	gconf2
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
