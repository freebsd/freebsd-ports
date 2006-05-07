# New ports collection makefile for:	cegui
# Date created:				03 Oct 2005
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cegui
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=crayzedsgui
DISTNAME=	${PORTNAME}_mk2-source-${PORTVERSION}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A library providing windowing and widgets for graphics APIs

LIB_DEPENDS=	IL.1:${PORTSDIR}/graphics/devil

WRKSRC=		${WRKDIR}/${PORTNAME}_mk2
CONFIGURE_ARGS=	--without-xerces-c
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
USE_GCC=	3.4
USE_BZIP2=	YES
USE_X_PREFIX=	YES
USE_GNOME=	gnomehack

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|"-lILU.*"|"-lm -L${LOCALBASE}/lib -lILU -lIL $$LIBS"|g; \
		s|-lpthread|${PTHREAD_LIBS}|g; \
		s|DevIL_CFLAGS=.*|DevIL_CFLAGS="-DUSE_DEVIL_LIBRARY -I${LOCALBASE}/include"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| Samples$$||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/include/CEGUIDataContainer.h
	@${REINPLACE_CMD} -e 's|__linux__)|& \|\| defined(__FreeBSD__)|g' \
		${WRKSRC}/include/CEGUIFactoryModule.h \
		${WRKSRC}/src/CEGUIFactoryModule.cpp
	@${REINPLACE_CMD} -e 's|(linux)|& \|\| defined(__FreeBSD__)|g' \
		${WRKSRC}/Samples/common/src/CEGuiSample.cpp

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in README COPYING AUTHORS ChangeLog TODO
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
