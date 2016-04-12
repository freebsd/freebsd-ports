# $FreeBSD$

PORTNAME=	wsjt
DISTVERSION=	${VERSION}.r${SVN_REV}
CATEGORIES=	comms hamradio
MASTER_SITES=	LOCAL/db
DISTNAME=	wsjt-r${SVN_REV}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/kvasd:comms/kvasd \
		${WSJT_DEPENDS}
BUILD_DEPENDS=	python:lang/python \
		${WSJT_DEPENDS}
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libsamplerate.so:audio/libsamplerate \
		libportaudio.so:audio/portaudio

WSJT_DEPENDS=	${PYTHON_LIBDIR}/lib-dynload/_tkinter.so:x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/scipy:science/py-scipy \
		${PYTHON_SITELIBDIR}/PIL:graphics/py-pillow \
		${PYNUMPY}

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
FETCH_DEPENDS+=	svn:devel/subversion
SVN_REV!=	svn info http://svn.code.sf.net/p/wsjt/wsjt/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:devel/subversion

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

post-patch:
	${REINPLACE_CMD} -e 's|%%PYTHON%%|${PYTHON_CMD}|'\
	    -e 's|%%PYTHON_VER%%|${PYTHON_VER}|'\
	    ${WRKSRC}/configure.ac

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in WSJT_Source_Code.txt UpdateHistory.txt LICENSE.TXT call_to.txt \
	calledby.txt wsjt7a.txt
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/wsjt/WsjtMod/Audio.so

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${FILESDIR}/wsjt ${WRKSRC}
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|%%PYTHON%%|${PYTHON_CMD}|' ${WRKSRC}/wsjt
	${INSTALL_SCRIPT} ${WRKSRC}/wsjt ${STAGEDIR}${LOCALBASE}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${LOCALBASE}/lib/wsjt/WsjtMod
.for d in Audio.so __init__.py astro.py g.py go.py options.py palettes.py \
	smeter.py specjt.py
	${INSTALL_DATA} ${WRKSRC}/WsjtMod/${d} ${STAGEDIR}${LOCALBASE}/lib/wsjt/WsjtMod
.endfor
.for d in CALL3.TXT dmet_10_-1_3.dat dmet_10_0_3.dat dmet_20_-2_2.dat \
	dmet_20_-3_2.dat wsjtrc wsjt.py Pmw.py PmwColor.py PmwBlt.py
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor
do-build:
	(cd ${WRKSRC};${GMAKE})

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
