# New ports collection makefile for:    MegaPov
# Date created:         25 July 2003
# Whom:                 maho@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	megapov
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://megapov.inetart.net/
DISTNAME=	${PORTNAME}-${PORTVERSION}_unix_s
EXTRACT_SUFX=   .tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Unofficial extensions of POV-Ray

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		vga:${PORTSDIR}/graphics/svgalib

WRKSRC=         ${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XLIB=	yes
USE_REINPLACE=  yes
USE_GMAKE=	yes
ALL_TARGET=     # empty

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double -Wunused-variable
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double  -Wunused-variable -Wno-multichar
.if (${MACHINE_ARCH} == "i386")
CFLAGS+=	-mcpu=i686 -march=i686 -mfancy-math-387
CXXFLAGS+=	-mcpu=i686 -march=i686 -mfancy-math-387
.endif # i386
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
	s|%%X11BASE%%|${X11BASE}|g ; \
	s|%%LOCALBASE%%|${LOCALBASE}|g ;\
	s|%%CC%%|${CC}|g ; \
	s|%%CXX%%|${CXX}|g ; \
	s|%%CFLAGS%%|${CFLAGS}|g ; \
	s|%%CXXFLAGS%%|${CXXFLAGS}|g'  ${WRKSRC}/unix/Makefile

.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

do-install:
	@(cd ${WRKSRC}/unix    ; ${GMAKE} install)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/manual
	@${TAR} -C ${WRKSRC}/manual -cf - . | \
		${TAR} -C ${DOCSDIR}/manual -xf -
	@${INSTALL_DATA} ${WRKSRC}/povlegal.doc ${DOCSDIR}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC} -cf - include scenes  | \
		${TAR} -C ${EXAMPLESDIR} -xf -
	@${FIND} ${EXAMPLESDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${EXAMPLESDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

.include <bsd.port.mk>
