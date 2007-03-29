# ex:ts=8
# Ports collection makefile for:	cheesetracker
# Date created:			Jan 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cheesetracker
PORTVERSION=	0.9.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cheesetronic

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Impulse Tracker clone

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
		qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		jack.0:${PORTSDIR}/audio/jack

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"
USE_SCONS=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%CFLAGS%%,${CFLAGS},' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's,%%QT_PREFIX%%,${QT_PREFIX},' ${WRKSRC}/detect.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cheesetracker/program__QT/cheesetracker_qt ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cheesetracker/examples/*.it ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/cheesetracker/examples/*.xm ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
