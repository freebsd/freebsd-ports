# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	wspr
DISTVERSION=	${VERSION}.r${SVN_REV}
PORTREVISION=	7
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	wspr-r${SVN_REV}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal for HF ham radio communication package

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	libhamlib.so:${PORTSDIR}/comms/hamlib \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		${PYNUMPY}

USES=		fortran gmake libtool tar:bzip2
ALL_TARGET=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gfortran --prefix=${STAGEDIR}${LOCALBASE} \
		--with-portaudio-include-dir=${LOCALBASE}/include/portaudio2 \
		--with-portaudio-lib-dir=${LOCALBASE}/lib/portaudio2
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_PYTHON=	yes
MAKE_ENV+=	PYTHONUSERBASE=${STAGEDIR}${PYTHONBASE}
PLIST_SUB=	PYVER=${PYTHON_VERSION:S/python//} \
		VERSION=${VERSION}
VERSION=	3.00

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>
post-configure:
	@${REINPLACE_CMD} -e 's|%%DESTDIR%%|${STAGEDIR}|' ${WRKSRC}/Makefile
	@cp ${FILESDIR}/wspr ${WRKSRC}

post-build:
	(cd ${STAGEDIR}${PREFIX} \
	    && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${WRKSRC}/LICENSE.TXT ${WRKSRC}/WSPR_Announcement.TXT \
	${WRKSRC}/WSPR0_Instructions.TXT ${WRKSRC}/WSPR_Quick_Start.TXT \
	${WRKSRC}/supported_rigs.txt
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor
.if defined(BOOTSTRAP)
SVN_REV!=	svn info http://svn.code.sf.net/p/wsjt/code/branches/wspr | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
		http://svn.code.sf.net/p/wsjt/code/branches/wspr ${WRKDIR}/wspr-r${SVN_REV}
	cd ${WRKDIR};rm -f ${DISTNAME}/*.a ${DISTNAME}/*.lib ${DISTNAME}/*.dll;\
		tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == db
	scp ${DISTDIR}/${DISTNAME}.tar.bz2 \
		freefall.freebsd.org:public_distfiles/
.endif
.endif

.include <bsd.port.post.mk>
