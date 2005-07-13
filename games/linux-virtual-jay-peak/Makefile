# New ports collection makefile for:	linux-virtual-jay-peak
# Date created:			03 Apr 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	virtual-jay-peak
PORTVERSION=	1.1a
CATEGORIES=	games linux
MASTER_SITES=	http://www.soulride.com/products/images/
PKGNAMEPREFIX=	linux-
DISTNAME=	virtual_jay_peak_linux_1_1a

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A simulation of snowboarding at the Jay Peak resort in Vermont

.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif

WRKSRC=		${WRKDIR}/soulride
ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_LINUX=	yes
NO_BUILD=	yes
SUB_FILES=	virtual-jay-peak

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/virtual-jay-peak ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/soulride-static ${PREFIX}/libexec

	${MKDIR} ${DATADIR}
.for d in Recordings data
	${CP} -R ${WRKSRC}/${d} ${DATADIR}
.endfor

	-${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/*
	${FIND} ${DATADIR}/* -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	${FIND} ${DATADIR}/* -type d -exec ${CHMOD} ${BINMODE} {} \;

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in readme-jay_peak.txt readme-linux.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
