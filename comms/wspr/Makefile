# $FreeBSD$

PORTNAME=	wspr
DISTVERSION=	${VERSION}.r${SVN_REV}
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	wspr-r${SVN_REV}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal for HF ham radio communication package

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYTHON_LIBDIR}/tkinter:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	libhamlib.so:${PORTSDIR}/comms/hamlib \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate

DISABLE_MAKE_JOBS=	yes
USE_AUTOTOOLS=	autoconf
USES=		fortran gmake libtool tar:bzip2 python:3.3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gfortran=${FC} \
		--with-f2py=f2py-${PYTHON_VER} \
		--with-python3=${PYTHON_CMD}
MAKE_ENV+=	PYTHONUSERBASE=${STAGEDIR}${PYTHONBASE}
LDFLAGS+=	-shared
VERSION=	4.00

.include <bsd.port.pre.mk>
pre-configure:
	@${CP} ${FILESDIR}/wspr.sh.in ${WRKSRC}

post-install:
.if defined(BOOTSTRAP)
#portlint freaks over this but it's only for dev ignore.
SVN_REV!=	svn info svn://svn.code.sf.net/p/wsjt/wsjt/branches/wspr | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		svn://svn.code.sf.net/p/wsjt/wsjt/branches/wspr ${WRKDIR}/wspr-r${SVN_REV}
	cd ${WRKDIR};rm -f ${DISTNAME}/*.a ${DISTNAME}/*.lib ${DISTNAME}/*.dll;\
		tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == db
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
		freefall.freebsd.org:public_distfiles/
.endif
.endif

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
