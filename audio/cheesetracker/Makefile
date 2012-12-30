# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cheesetracker
PORTVERSION=	0.9.15.4
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Impulse Tracker clone

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_QT_VER=	3
USE_SCONS=	yes
USE_PKGCONFIG=	build
SCONS_BUILDENV=	CXX="${CXX}" QTDIR="${QT_PREFIX}"

PORTEXAMPLES=	beek-dolphinisland.it ll-globule.it reduz-maschizo.it \
		xerxes-mfc.xm
PLIST_FILES=	bin/cheesetracker_qt

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

.if ${ARCH} != "i386"
LIB_DEPENDS+=	gmp.10:${PORTSDIR}/math/gmp
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CXXFLAGS%%|${CXXFLAGS}| ; \
		 s|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g ; \
		 s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%QT_PREFIX%%|${QT_PREFIX}|' ${WRKSRC}/detect.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cheesetracker/program__QT/cheesetracker_qt ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cheesetracker/examples/*.it ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cheesetracker/examples/*.xm ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
