# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=		FlightGear
PORTVERSION=		0.6.1
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.flightgear.org/pub/fgfs/Source/ \
			ftp://ftp.flightgear.org/pub/fgfs/Shared/
DISTFILES=		${DISTNAME}.tar.gz \
			fgfs-base-${PORTVERSION}.tar.gz

MAINTAINER=		brian@CSUA.Berkeley.EDU

BUILD_DEPENDS=		${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
RUN_DEPENDS=		mpg123:${PORTSDIR}/audio/mpg123

EXTRACT_ONLY=		${DISTNAME}.tar.gz

.if defined(BUILD_SCENERY_TOOLS)
MASTER_SITES+=		ftp://ftp.cs.man.ac.uk/pub/amurta/
DISTFILES+=		gfc-0.8.8.1b.tar.gz gpc231.tar.Z
EXTRACT_ONLY+=		gfc-0.8.8.1b.tar.gz gpc231.tar.Z
NO_PACKAGE=		"gpc's license conflicts with the GPL"
CONFIGURE_ENV+=		CPPFLAGS=-I${WRKSRC}/gfcgpc/include \
			LDFLAGS=-L${WRKSRC}/gfcgpc/lib
ADDPATCHES=		${MASTERDIR}/patches.tools/gfc-patch-aa

pre-configure:
	@(cd ${WRKDIR}/gfc-0.8.8.1b; ./configure --prefix=${WRKSRC}/gfcgpc; \
	  ${GMAKE}; ${GMAKE} install; \
	  ${CP} ${MASTERDIR}/patches.tools/Makefile.gpc \
	        ${WRKDIR}/gpc231/Makefile; \
	  cd ${WRKDIR}/gpc231; ${GMAKE}; \
	  ${GMAKE} PREFIX=${WRKSRC}/gfcgpc install)
.else
PLIST=		${MASTERDIR}/pkg-plist.notools
ADDPATCHES=	${MASTERDIR}/patches.tools/disable-tools
USE_AUTOCONF_VER=213
.endif

USE_NEWGCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	LDFLAGS="${LDFLAGS} -L${X11BASE}/lib -lGLU -lGL -lglut ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=--bindir=${PREFIX}/FlightGear/bin
USE_GMAKE=	yes

pre-patch:
	@( cd ${WRKDIR}; \
	   for i in ${ADDPATCHES} ; do \
		${PATCH} -s < $${i}; \
	   done )

post-configure:
	@find ${WRKSRC} -type f | xargs ${PERL} -pi -e \
		"s@#include.*<malloc.h>@#include <stdlib.h>@g"
	@(cd ${WRKSRC};touch Makefile.in */Makefile.in */*/Makefile.in \
	                     */*/*/Makefile.in; \
	  ./config.status)

pre-install:
	cd ${PREFIX}; \
	${TAR} xzf ${DISTDIR}/fgfs-base-${PORTVERSION}.tar.gz

post-install:
	${MV} ${PREFIX}/FlightGear/bin/runfgfs ${PREFIX}/bin

.include <bsd.port.mk>
