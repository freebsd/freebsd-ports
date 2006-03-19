# New ports collection makefile for:	gpsim
# Date created:		2006-03-13
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	gpsim
PORTVERSION=	0.21.11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	A software simulator for Microchip PIC microcontrollers

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gtkextra-x11-2.0.1:${PORTSDIR}/x11-toolkits/gtkextra2
RUN_DEPENDS=	gpasm:${PORTSDIR}/devel/gputils

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.4+
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/4patch-*
.endif

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
