# New ports collection makefile for:	Schism Tracker
# Date created:				26 May 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	schism
PORTVERSION=	20081004
CATEGORIES=	audio
MASTER_SITES=	http://nimh.org/schism/ \
		CRITICAL
DISTNAME=	cvs-snapshot
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A module tracker editor/player resembling impulse tracker

ONLY_FOR_ARCHS=	i386 amd64

USE_SDL=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		currently does not support 8-CURRENT
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/schismtracker ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
