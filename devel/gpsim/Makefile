# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	gpsim
PORTVERSION=	0.22.0
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER= ports@FreeBSD.org
COMMENT=	Software simulator for Microchip PIC microcontrollers

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libgtkextra-x11-2.0.so:${PORTSDIR}/x11-toolkits/gtkextra2
RUN_DEPENDS=	gpasm:${PORTSDIR}/devel/gputils

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/os_dependent.cc
	@${REINPLACE_CMD} -e 's|glibconfig.h|glib.h|g' \
		${WRKSRC}/src/bitlog.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in AUTHORS ChangeLog PROCESSORS README* doc/gpsim.pdf
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
		${FIND} * -type d -exec ${MKDIR} "${EXAMPLESDIR}/{}" \; && \
		${FIND} -E * -type f -iregex ".*\.(asm|stc|inc)" -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;

.include <bsd.port.post.mk>
