# New ports collection makefile for:   	squeak
# Date created:        			12 October 2001
# Whom:                			roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	squeak
PORTVERSION=	3.5
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.5/ \
		http://www-sor.inria.fr/~piumarta/squeak/unix/release/ \
		ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.4/unix-linux/ \
		ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.4/unix-linux/
DISTNAME=	Squeak-${SQUEAK_VERSION}.src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SQUEAK_SRC} ${SQUEAK_IMAGE_SRC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	roland.jesse@gmx.net
COMMENT=	Full Smalltalk 80 with portability to UNIX, Mac, and Windows

# Don't set USE_ZIP as this breaks EXTRACT_CMD, EXTRACT_SUFX, and what not.
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

SQUEAK_VERSION=	3.4-1
SQUEAK_IMAGE_VERSION=	3.5
SQUEAK_PATCHNR=	5180
SQUEAK_SRC=	SqueakV3.sources.gz
SQUEAK_IMAGE_SRC=	Squeak${SQUEAK_IMAGE_VERSION}-${SQUEAK_PATCHNR}.zip
SQUEAK_IMAGE=	Squeak${SQUEAK_IMAGE_VERSION}-${SQUEAK_PATCHNR}.image \
		Squeak${SQUEAK_IMAGE_VERSION}-${SQUEAK_PATCHNR}.changes

WRKSRC=		${WRKDIR}/Squeak-${SQUEAK_VERSION}
MAN1=		inisqueak.1 squeak.1
USE_XLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
LDCONFIG_DIRS=	${PREFIX}/share/squeak/${SQUEAK_VERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../platforms/unix/config/configure
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share
# don't pass "-s" to install to avoid trying to strip a shell script
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}"
BUILD_WRKSRC=	${WRKSRC}/build
DIST_SUBDIR=	squeak

.ifdef (WITHOUT_AUDIO)
CONFIGURE_ARGS+=	--without-audio
.else
LIB_DEPENDS+=		audio.2:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=	--with-audio=nas
.endif

.ifdef (WITH_MMX)
CONFIGURE_ARGS+=	--enable-mpg-mmx
.endif

MAKEFILE=	Makefile
.ifdef (CC)
MAKE_ARGS+=	CC=${CC}
.endif
.ifdef (CFLAGS)
MAKE_ARGS+=	CCFLAGS="${CFLAGS}"
.endif

pre-configure:
	@${MKDIR} ${BUILD_WRKSRC}
	@cd ${WRKSRC}/platforms/unix/npsqueak && ${REINPLACE_CMD} -e 's|include|include -I${X11BASE}/include|g' Makefile

post-configure:
# PREFIX safeness
	@${REINPLACE_CMD} -E \
		-e s'|^(prefix).*$$|\1=${PREFIX}|' \
		-e s'|^(docdir).*$$|\1=${DOCSDIR}|' \
		${CONFIGURE_WRKSRC}/${MAKEFILE}

post-install:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${SQUEAK_SRC} ${PREFIX}/share/squeak/)
	(cd ${PREFIX}/share/squeak && ${EXTRACT_CMD} -d ${SQUEAK_SRC})
	(cd ${PREFIX}/share/squeak && unzip -x ${DISTDIR}/${DIST_SUBDIR}/${SQUEAK_IMAGE_SRC})
.for file in ${SQUEAK_IMAGE}
	(cd ${PREFIX}/share/squeak && ${GZIP_CMD} ${file})
.endfor
# install inisqueak and change the build in version number on the fly
	${SED} \
		-e 's|VERSION=3.4-5170|VERSION=3.5-5180|' \
		-e 's|IMAGE=squeak|IMAGE=Squeak3.5-5180|' \
		-e 's|CHANGES=squeak|CHANGES=Squeak3.5-5180|' \
		${WRKSRC}/build/inisqueak > ${PREFIX}/bin/inisqueak
	${CHMOD} 755 ${PREFIX}/bin/inisqueak
	${STRIP_CMD} ${PREFIX}/share/squeak/${SQUEAK_VERSION}/squeak
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
