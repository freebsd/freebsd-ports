# New ports collection makefile for:   	squeak
# Date created:        			12 October 2001
# Whom:                			roland.jesse@gmx.net
#
# $FreeBSD$
#

##################################################
PORTNAME=		squeak
PORTVERSION=		3.6
PORTREVISION=		1
CATEGORIES=		lang
VMVERSION=		3.6-3
IMAGEVERSION=		3.6
PATCHNUMBER=		5429

##################################################
MASTER_SITES=		ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.6/ \
			ftp://st.cs.uiuc.edu/Smalltalk/Squeak/3.6/unix-linux/ \
			ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.6/ \
			ftp://ftp.cs.uni-magdeburg.de/pub/Smalltalk/Smalltalk/Squeak/3.6/unix-linux/ \
			http://www-sor.inria.fr/~piumarta/squeak/unix/release/ \

DISTFILES=		Squeak-${VMVERSION}.src.tar.gz \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-basic.zip \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-full.zip \
			SqueakV3.sources.gz

DIST_SUBDIR=		squeak
EXTRACT_ONLY=		Squeak-${VMVERSION}.src.tar.gz

##################################################
MAINTAINER=		chris@chrisburkert.de
COMMENT=		Full Smalltalk 80 with portability to UNIX, Mac, and Windows.

##################################################
ONLY_FOR_ARCHS= 	i386
MAN1=			inisqueak.1 squeak.1
USE_GMAKE=		yes
HAS_CONFIGURE=		yes

# Don't set USE_ZIP as this breaks EXTRACT_CMD.
BUILD_DEPENDS=		unzip:${PORTSDIR}/archivers/unzip

# shared Libaries are to be installed in:
LDCONFIG_DIRS=		${PREFIX}/share/squeak/${VMVERSION}

FILES_TO_GZIP=		Squeak${IMAGEVERSION}-${PATCHNUMBER}-basic.image \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-basic.changes \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-full.image \
			Squeak${IMAGEVERSION}-${PATCHNUMBER}-full.changes

##################################################
# Configure and Build
WRKSRC=			${WRKDIR}/Squeak-${VMVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=		${CONFIGURE_WRKSRC}
CONFIGURE_SCRIPT=	../platforms/unix/config/configure
CONFIGURE_ARGS+=	--libdir=${PREFIX}/share \
			--without-quartz
# don't pass "-s" to install to avoid trying to strip a shell script
CONFIGURE_ENV=

##################################################
# Knobs
.if defined(WITH_RFB) && (${WITH_RFB}=="no")
CONFIGURE_ARGS+=        --without-rfb
.endif

.if defined(WITH_NPSQUEAK) && (${WITH_NPSQUEAK}=="no")
CONFIGURE_ARGS+=        --without-npsqueak
PLIST_NPSQUEAK=         "@comment feature not wanted - "
.else
PLIST_NPSQUEAK=
.endif

.if defined(WITH_X) && (${WITH_X}=="no")
CONFIGURE_ARGS+=        --without-x
PLIST_X=		"@comment feature not wanted - "
.else
USE_XLIB=              yes
CONFIGURE_ARGS+=        --with-x
PLIST_X=
.endif

.if defined(WITH_MPG_MMX) && (${WITH_MPG_MMX}=="yes")
CONFIGURE_ARGS+=        --enable-mpg-mmx
.endif

.ifdef (CC)
MAKE_ARGS+=		CC="${CC}"
.endif

.ifdef (CFLAGS)
MAKE_ARGS+=		CCFLAGS="${CFLAGS}"
.endif

PLIST_SUB=              IMAGEVERSION=${IMAGEVERSION}\
			PATCHNUMBER=${PATCHNUMBER}\
			VMVERSION=${VMVERSION}\
			PLIST_NPSQUEAK=${PLIST_NPSQUEAK}\
			PLIST_X=${PLIST_X}

.include <bsd.port.pre.mk>

##################################################
pre-everything::
	@${ECHO_MSG} " "
	@${ECHO_MSG} " ------------------------- Please note: -------------------------"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "  Squeak has the following tunable options:"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "    WITH_MPG_MMX=      [yes|no]  MMX support (MPG plugin)"
	@${ECHO_MSG} "                            ^^   (default: disabled)"
	@${ECHO_MSG} "    WITH_NPSQUEAK=     [yes|no]  browser plugin support"
	@${ECHO_MSG} "                        ^^^      (default: enabled)"
	@${ECHO_MSG} "    WITH_RFB=          [yes|no]  remote frame buffer support"
	@${ECHO_MSG} "                        ^^^      (default: enabled)"
	@${ECHO_MSG} "    WITH_X=            [yes|no]  X Windows support"
	@${ECHO_MSG} "                        ^^^      (default: enabled)"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "  additional make arguments"
	@${ECHO_MSG} "    CC=<aString>"
	@${ECHO_MSG} "    CFLAGS=<aString>"
	@${ECHO_MSG} " "
	@${ECHO_MSG} " ------------------ Thanks for your attention! ------------------"
	@${ECHO_MSG} " "

##################################################
pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@cd ${WRKSRC}/platforms/unix/npsqueak && \
		${REINPLACE_CMD} -e 's|include|include -I${X11BASE}/include|g' Makefile

##################################################
post-configure:
	@${REINPLACE_CMD} -E \
		-e s'|^(prefix).*$$|\1=${PREFIX}|' \
		-e s'|^(docdir).*$$|\1=${DOCSDIR}|' \
		${CONFIGURE_WRKSRC}/Makefile

##################################################
post-install:
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} SqueakV3.sources.gz ${PREFIX}/share/squeak/)
	(cd ${PREFIX}/share/squeak && ${EXTRACT_CMD} -d SqueakV3.sources.gz)
	(cd ${DISTDIR}/${DIST_SUBDIR} && unzip -u Squeak${IMAGEVERSION}-${PATCHNUMBER}-basic.zip -d ${WRKDIR})
	(cd ${DISTDIR}/${DIST_SUBDIR} && unzip -u Squeak${IMAGEVERSION}-${PATCHNUMBER}-full.zip -d ${WRKDIR})
	(cd ${WRKDIR} && ${INSTALL_DATA} ReadMe.txt ${PREFIX}/share/squeak/)
.for file in ${FILES_TO_GZIP}
	(cd ${WRKDIR} && ${GZIP_CMD} ${file} && ${INSTALL_DATA} ${file}.gz ${PREFIX}/share/squeak/)
.endfor
	${SED}	-e 's|VERSION=3.5-5180|VERSION=${IMAGEVERSION}-${PATCHNUMBER}|' \
		-e 's|IMAGE=Squeak3.5-5180|IMAGE=Squeak${IMAGEVERSION}-${PATCHNUMBER}|' \
		-e 's|CHANGES=Squeak3.5-5180|CHANGES=Squeak${IMAGEVERSION}-${PATCHNUMBER}|' \
		${WRKSRC}/build/inisqueak > ${WRKSRC}/build/inisqueak.tmp
	${INSTALL_SCRIPT} ${WRKSRC}/build/inisqueak.tmp ${PREFIX}/bin/inisqueak
	${CHMOD} 755 ${PREFIX}/bin/inisqueak
	@${ECHO_MSG} " "
	@${ECHO_MSG} " ------------------------- Please note: -------------------------"
	@${ECHO_MSG} " "
	@${ECHO_MSG} "  In order to be able to make use of squeak you need to have an"
	@${ECHO_MSG} "    image and a changes file in your working directory as well"
	@${ECHO_MSG} "    as access to a source file. This is easy by using inisqueak."
	@${ECHO_MSG} "    Please see the inisqueak(1) manpage for details."
	@${ECHO_MSG} " "
	@${ECHO_MSG} "  Make sure you have the following values in your environment"
	@${ECHO_MSG} "    variables:"
	@${ECHO_MSG} "    PATH:            ${PREFIX}/bin"
	@${ECHO_MSG} "    LD_LIBRARY_PATH: ${PREFIX}/lib"
	@${ECHO_MSG} "                     ${PREFIX}/share/squeak/${VMVERSION}"
	@${ECHO_MSG} " "
	@${ECHO_MSG} " ------------------ Thanks for your attention! ------------------"
	@${ECHO_MSG} " "

.include <bsd.port.post.mk>
