# New ports collection makefile for:	wspr
# Date created:				30 April 2009
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	wspr
PORTVERSION=	2.00
PORTREVISION=	3
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.physics.princeton.edu/pulsar/K1JT/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	wspr-${PORTVERSION}.r1714

MAINTAINER=	db@FreeBSD.org
COMMENT=	Weak signal for HF ham radio communication package

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter/ \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		samplerate:${PORTSDIR}/audio/libsamplerate
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		${PYNUMPY}

BROKEN=		does not build

ALL_TARGET=	build
EXTRACT_SUFX=	.tgz
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

post-configure:
	@${REINPLACE_CMD} -e 's|-Wl.*||' ${WRKSRC}/Makefile

post-install:
.if	!defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for d in ${WRKSRC}/LICENSE.TXT ${WRKSRC}/WSPR_Announcement.TXT \
	${WRKSRC}/WSPR_Instructions.TXT ${WRKSRC}/WSPR_Quick_Start.TXT \
	${WRKSRC}/supported_rigs.txt
	${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO}
	@${ECHO} "docs installed in ${DOCSDIR}"
	@${ECHO}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
