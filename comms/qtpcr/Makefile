# New ports collection makefile for:	qtpcr
# Date created:			31 Jan 2003
# Whom:				Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	qtpcr
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.physics.purdue.edu/~teepanis/qtpcr/
DISTNAME=	qtpcr-${PORTVERSION}

MAINTAINER=	esn@x123.info
COMMENT=	Software that controls the ICOM PCR-1000 Receiver

WRKSRC=		${WRKDIR}/qtpcr-${PORTVERSION}/src

USE_X_PREFIX=	yes
ALL_TARGET=
INSTALL_TARGET=
PLIST_FILES=	bin/qtpcr

.if defined(WITH_QT23)
USE_QT_VER=	2
MAKE_ENV=	INCPATH=-I${X11BASE}/include/qt2 MOC=moc2 LIBS="-lqt2-mt -L${X11BASE}/lib ${PTHREAD_LIBS}"
.else
USE_QT_VER=	3
MAKE_ENV=	INCPATH=-I${X11BASE}/include MOC=moc LIBS="-lqt-mt -L${X11BASE}/lib ${PTHREAD_LIBS}"
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(WITH_QT23)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_QT23=yes to use qt23, else it will use the current qt"
	@${ECHO_MSG} ""
.endif

post-install:
	@${ECHO_MSG} "===>   Installing qtpcr in ${X11BASE}/bin/qtpcr"
	@${ECHO_MSG} ""
	${INSTALL_PROGRAM} ${WRKSRC}/qtpcr ${X11BASE}/bin
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Remember to create a symbolic link from your com(0|1) to /dev/pcr1000"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
