# New ports collection makefile for:	wsjt
# Date created:				3rd August 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	wsjt
PORTVERSION=	7.04
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	wsjt-r${SVN_REV}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter/ \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	fftw3f:${PORTSDIR}/math/fftw3-float \
		samplerate:${PORTSDIR}/audio/libsamplerate
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		${PYNUMPY}

BROKEN=		does not build

ALL_TARGET=	build
USE_BZIP2=	yes
USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gfortran --prefix=${LOCALBASE} \
		--with-portaudio-include-dir=${LOCALBASE}/include/portaudio2 \
		--with-portaudio-lib-dir=${LOCALBASE}/lib/portaudio2
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_PYTHON=	2.5+
USE_AUTOTOOLS=	libtool
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//} \
		PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>
post-configure:
	@${REINPLACE_CMD} -e 's|-Wl.*||' ${WRKSRC}/Makefile

post-install:
.if	!defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for d in ${WRKSRC}/WSJT_Quick_Reference.pdf  ${WRKSRC}/WSJT_Source_Code.txt \
	${WRKSRC}/WSJT_User_600.pdf ${WRKSRC}/UpdateHistory.txt \
	${WRKSRC}/WSJT_Source_Code.txt ${WRKSRC}/LICENSE.TXT
	${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO}
	@${ECHO} "docs installed in ${DOCSDIR}"
	@${ECHO}
.endif
	@${CAT} ${PKGMESSAGE}

.if defined(BOOTSTRAP)
SVN_REV!=	svn info http://svn.berlios.de/svnroot/repos/wsjt/trunk/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif

.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    http://svn.berlios.de/svnroot/repos/wsjt/trunk ${WRKSRC}
	cd ${WRKDIR};rm -f ${DISTNAME}/*.a ${DISTNAME}/*.lib ${DISTNAME}/*.dll;\
		tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=	${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == db
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif

.include <bsd.port.post.mk>
