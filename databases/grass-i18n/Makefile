# New ports collection makefile for:	grass-i18n
# Date created:		20 Aug 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	grass-i18n
PORTVERSION=	5.0.3
CATEGORIES=	databases
MASTER_SITES=	http://www.grass-japan.org/FOSS4G/GRASS/:grass \
		http://www.grass-japan.org/FOSS4G/ipafonts/:ipafonts
PKGNAMESUFFIX=	+ipafont
DISTFILES=	${FILES_SRC}:grass ${FILES_TKI18N}:grass ${FILES_FONTS}:ipafonts
EXTRACT_ONLY=	${FILES_SRC}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	An open source Geographical Information System (GIS), i18n version

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gd.4:${PORTSDIR}/graphics/gd \
		fftw.2:${PORTSDIR}/math/fftw \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		lapack.3:${PORTSDIR}/math/lapack

CONFLICTS=	grass-[0-9]*

FILES_SRC=	grass${PORTVERSION}_i18n_src${EXTRACT_SUFX}
FILES_TKI18N=	tcltkgrass-i18n${EXTRACT_SUFX}
FILES_FONTS=	grass${PORTVERSION}_i686-pc-linux-i18n-ipafull-gnu_bin${EXTRACT_SUFX}

.if defined(WITH_POSTGRES)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT} \
		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-postgres \
		--with-postgres-includes=${LOCALBASE}/include/postgresql/internal/ \
		--with-odbc
PLIST_SUB+=	POSTGRES=""
.else
CONFIGURE_ARGS+=--without-postgres \
		--without-odbc
PLIST_SUB+=	POSTGRES="@comment "
.endif

.if defined(WITH_TCLTK)
BUILD_DEPENDS+=	tclsh8.3:${PORTSDIR}/lang/tcl83 \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS+=	tclsh8.3:${PORTSDIR}/lang/tcl83 \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83
CONFIGURE_ARGS+=--with-tcltk \
		--with-tcltk-includes="${LOCALBASE}/include/tcl8.3 \
					 ${LOCALBASE}/include/tk8.3"
PLIST_SUB+=	TCLTK=""
.else
CONFIGURE_ARGS+=--without-tcltk
PLIST_SUB+=	TCLTK="@comment "
.endif

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude *CVS*

WRKSRC=		${WRKDIR}/grass-${PORTVERSION}-i18n

USE_ICONV=	yes
USE_XLIB=	yes
USE_GL=		yes
USE_PERL5=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213

CONFIGURE_ARGS+=--with-includes=${LOCALBASE}/include \
		--with-libs=${LOCALBASE}/lib \
		--with-opengl-includes=${X11BASE}/include \
		--with-opengl-libs=${X11BASE}/lib \
		--with-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype2 \
		--with-blas \
		--with-lapack \
		--with-nls \
		--without-motif

CONFIGURE_IN_SUB=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
			PTHREAD_LIBS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

pre-extract:
	@${ECHO_CMD} "You can specify the following build options:"
	@${ECHO_CMD} "	WITH_POSTGRES=YES: build with PostgreSQL support"
	@${ECHO_CMD} "	WITH_TCLTK=YES:    build with TclTk support"
	@${ECHO_CMD} ""

post-extract:
	cd ${WRKDIR} && ${TAR} xzf \
		${DISTDIR}/${FILES_FONTS} ./fonts/\*.ttf ./license-ipafonts.eucjp
	${MKDIR} ${WRKDIR}/tcltkgrass-i18n
	cd ${WRKDIR}/tcltkgrass-i18n && ${TAR} xzf \
		${DISTDIR}/${FILES_TKI18N}
	${RM} -rf `${FIND} ${WRKDIR}/tcltkgrass-i18n -type d -a -name cvs`
.for D in docs main module script
	${MV} ${WRKSRC}/src/tcltkgrass/${D} ${WRKSRC}/src/tcltkgrass/${D}.orig
	${MV} ${WRKDIR}/tcltkgrass-i18n/tcltkgrass-i18n/${D} ${WRKSRC}/src/tcltkgrass/${D}
.endfor

post-patch:
	${CP} ${WRKSRC}/configure.in ${WRKSRC}/configure.in.orig
	${SED} ${CONFIGURE_IN_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${WRKSRC}/configure.in.orig \
		> ${WRKSRC}/configure.in

post-install:
	cd ${WRKDIR}/tcltkgrass-i18n/scripts && ${TAR} cf - . | \
		(cd ${PREFIX}/grass5/scripts && ${TAR} xf -)
.if defined(WITH_TCLTK)
	cd ${WRKDIR}/tcltkgrass-i18n/bin && ${TAR} cf - . | \
		(cd ${PREFIX}/grass5/bin && ${TAR} xf -)
	cd ${WRKDIR}/tcltkgrass-i18n/etc && ${TAR} cf - ./nviz2.2-i18n | \
		(cd ${PREFIX}/grass5/etc && ${TAR} xf -)
	cd ${WRKDIR}/tcltkgrass-i18n/documents && ${TAR} cf - ./nviz | \
		(cd ${PREFIX}/grass5/documents && ${TAR} xf -)
.endif
	${INSTALL_DATA} ${WRKDIR}/fonts/*.ttf \
			${WRKDIR}/license-ipafonts.eucjp \
			${PREFIX}/grass5/fonts/
	-(cd ${PREFIX} && ${GREP} -v "@" ${PLIST} | \
	  ${XARGS} ${STRIP_CMD} 2> /dev/null || ${TRUE})

.include <bsd.port.post.mk>
