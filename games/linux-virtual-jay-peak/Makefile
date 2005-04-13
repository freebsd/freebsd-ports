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

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs \
		${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/graphics/linux_mesa3

WRKSRC=		${WRKDIR}/soulride
ONLY_FOR_ARCHS=	i386
PREFIX?=	${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB
USE_LINUX=	yes
NO_BUILD=	yes
STRIP=		# do not brand Linux binaries as FreeBSD on INSTALL_PROGRAM

post-patch:
	@${SED} -e 's|@DATADIR@|${DATADIR}|; s|@LIBEXECDIR@|${PREFIX}/libexec|' \
		${FILESDIR}/virtual-jay-peak.in > ${WRKSRC}/virtual-jay-peak

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/virtual-jay-peak ${PREFIX}/bin

	${MKDIR} ${PREFIX}/libexec
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
