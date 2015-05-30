# $FreeBSD$

PORTNAME=	wsjt
VERSION=	9.1
PORTREVISION=	11
DISTVERSION=	${VERSION}.r${SVN_REV}
CATEGORIES=	comms hamradio
MASTER_SITES=	LOCAL/db
DISTNAME=	wsjt-r${SVN_REV}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow
LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libportaudio.so:${PORTSDIR}/audio/portaudio
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${PYNUMPY}

USE_GCC=	yes
USES=		fortran gmake python tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gfortran --prefix=${STAGEDIR}${LOCALBASE} \
		--with-portaudio-include-dir=${LOCALBASE}/include/ \
		--with-portaudio-lib-dir=${LOCALBASE}/lib/
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
# Adding this breaks configure
#LDFLAGS+=	-shared
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//} \
		VERSION=${VERSION}

.include <bsd.port.pre.mk>

.if defined(BOOTSTRAP)
SVN_REV!=	svn info http://svn.code.sf.net/p/wsjt/code/trunk/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		http://svn.code.sf.net/p/wsjt/code/trunk ${WRKDIR}/wsjt-r${SVN_REV}
	cd ${WRKDIR};rm -f ${DISTNAME}/*.a ${DISTNAME}/*.lib ${DISTNAME}/*.dll;\
		tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == db
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
		freefall.freebsd.org:public_distfiles/
.endif
.endif

pre-patch:
	@${CP}	${FILESDIR}/configure ${WRKSRC}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${WRKSRC}/WSJT_Quick_Reference.pdf  ${WRKSRC}/WSJT_Source_Code.txt \
	${WRKSRC}/WSJT_User_600.pdf ${WRKSRC}/UpdateHistory.txt \
	${WRKSRC}/WSJT_Source_Code.txt ${WRKSRC}/LICENSE.TXT
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor

do-build:
	(cd ${WRKSRC};${GMAKE})

post-stage:
	(cd ${STAGEDIR}${PREFIX} \
	  && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
	   -d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.post.mk>
