# New ports collection makefile for:	wspr
# Date created:				30 April 2009
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	wspr
PORTVERSION=	1.11
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	wspr-r${SVN_REV}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Weak signal for HF ham radio communication package

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter/ \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float \
		samplerate:${PORTSDIR}/audio/libsamplerate
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		${PYNUMPY}

ALL_TARGET=	build
USE_BZIP2=	yes
USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gfortran --prefix=${LOCALBASE} \
		--with-portaudio-include-dir=${LOCALBASE}/include/portaudio2 \
		--with-portaudio-lib-dir=${LOCALBASE}/lib/portaudio2
CONFIGURE_ENV=	CFLAGS+="-I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
USE_PYTHON=	2.4+
USE_AUTOTOOLS=	libtool:22
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//} \
		PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.if defined(BOOTSTRAP)
SVN_REV!=	svn info http://svn.berlios.de/svnroot/repos/wsjt/branches/wspr/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    http://svn.berlios.de/svnroot/repos/wsjt/branches/wspr ${WRKSRC}
	cd ${WRKDIR};rm -f ${DISTNAME}/*.a ${DISTNAME}/*.lib ${DISTNAME}/*.dll;\
		tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=	${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == db
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif

.include <bsd.port.post.mk>
