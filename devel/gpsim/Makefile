# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	gpsim
PORTVERSION=	0.29.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software simulator for Microchip PIC microcontrollers

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	gpasm:devel/gputils
LIB_DEPENDS=	libpopt.so:devel/popt
RUN_DEPENDS=	gpasm:devel/gputils

USES=		gmake libtool pathfix pkgconfig readline
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS EXAMPLES GTK2
OPTIONS_DEFAULT=	GTK2
OPTIONS_SUB=		yes

GTK2_LIB_DEPENDS=	libgtkextra-x11-2.0.so:x11-toolkits/gtkextra2
GTK2_USE=		gnome=gtk20
GTK2_CONFIGURE_ENABLE=	gui
GTK2_DESKTOP_ENTRIES=	"GPSim" "" "" "gpsim" "Development;GTK;" ""

post-patch:
.for i in gpsim/Makefile.in modules/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-lstdc++||' ${WRKSRC}/${i}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog PROCESSORS README* doc/gpsim.pdf
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
.for i in led_test logic_test mod_test usart_gui usart_test
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/modules/${i}
	(cd ${WRKSRC}/examples/modules/${i} && ${INSTALL_DATA} *.asm *.stc \
		${STAGEDIR}${EXAMPLESDIR}/modules/${i})
.endfor
.for i in digital_stim p16f628_test stack_test
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/projects/${i}
	(cd ${WRKSRC}/examples/projects/${i} && ${INSTALL_DATA} *.asm *.stc \
		${STAGEDIR}${EXAMPLESDIR}/projects/${i})
.endfor

.include <bsd.port.mk>
