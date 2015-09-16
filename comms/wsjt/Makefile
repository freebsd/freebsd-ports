# $FreeBSD$

PORTNAME=	wsjt
DISTVERSION=	${VERSION}.r${SVN_REV}
CATEGORIES=	comms hamradio
MASTER_SITES=	LOCAL/db
DISTNAME=	wsjt-r${SVN_REV}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

LICENSE=	GPLv3

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libportaudio.so:${PORTSDIR}/audio/portaudio
WSJT_DEPENDS=	${PYTHON_LIBDIR}/lib-dynload/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${PYTHON_SITELIBDIR}/PIL:${PORTSDIR}/graphics/py-pillow \
		${PYNUMPY}
BUILD_DEPENDS=	${WSJT_DEPENDS}
RUN_DEPENDS=	${LOCALBASE}/bin/kvasd:${PORTSDIR}/comms/kvasd \
		${WSJT_DEPENDS}

USE_GCC=	yes
USES=		autoreconf fortran gmake python:3.3+ tar:bzip2
SHEBANG_FILES=	${WRKSRC}/wsjt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${STAGEDIR}${LOCALBASE} \
		--with-portaudio-include-dir=${LOCALBASE}/include \
		--with-portaudio-lib-dir=${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
# Adding this breaks configure
#LDFLAGS+=	-shared
VERSION=	10
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//} \
		VERSION=${VERSION}

.include <bsd.port.pre.mk>

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
#portlint freaks over this but it's only for dev. so ignore.
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
SVN_REV!=	svn info http://svn.code.sf.net/p/wsjt/wsjt/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		http://svn.code.sf.net/p/wsjt/wsjt/trunk ${WRKDIR}/wsjt-r${SVN_REV}
	cd ${WRKDIR};rm -f ${DISTNAME}/*.a ${DISTNAME}/*.lib ${DISTNAME}/*.dll;\
		tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	${ECHO_CMD} "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == db
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
		freefall.freebsd.org:public_distfiles/
.endif
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${FILESDIR}/wsjt ${WRKSRC}
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    ${WRKSRC}/wsjt
	${REINPLACE_CMD} -e 's|%%PYTHON%%|${PYTHON_CMD}|' \
	    ${WRKSRC}/wsjt
	${INSTALL_SCRIPT} ${WRKSRC}/wsjt ${STAGEDIR}${LOCALBASE}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${LOCALBASE}/lib/wsjt/WsjtMod
.for d in ${WRKSRC}/WsjtMod/Audio.so ${WRKSRC}/WsjtMod/__init__.py \
	${WRKSRC}/WsjtMod/astro.py ${WRKSRC}/WsjtMod/g.py \
	${WRKSRC}/WsjtMod/go.py ${WRKSRC}/WsjtMod/options.py \
	${WRKSRC}/WsjtMod/palettes.py ${WRKSRC}/WsjtMod/smeter.py \
	${WRKSRC}/WsjtMod/specjt.py
	${INSTALL_DATA} ${WRKSRC}${d} ${STAGEDIR}${LOCALBASE}/lib/wsjt/WsjtMod
.endfor
.for d in ${WRKSRC}/CALL3.TXT  ${WRKSRC}/dmet_10_-1_3.dat \
	${WRKSRC}/dmet_10_0_3.dat ${WRKSRC}/dmet_20_-2_2.dat \
	${WRKSRC}/dmet_20_-3_2.dat ${WRCSRC}/wsjtrc ${WRCSRC}/wsjt.py \
	${WRKSRC}/Pmw.py ${WRKSRC}/PmwColor.py ${WRKSRC}/PmwBlt.py
	${INSTALL_DATA} ${WRKSRC}${d} ${STAGEDIR}${DATADIR}
.endfor
do-build:
	(cd ${WRKSRC};${GMAKE})

post-configure:
	${REINPLACE_CMD} -e 's|f2py|f2py-${PYTHON_VER}|' \
	    ${WRKSRC}/Makefile

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
