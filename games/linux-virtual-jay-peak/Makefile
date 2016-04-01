# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virtual-jay-peak
PORTVERSION=	1.1a
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://www.soulride.com/products/images/
PKGNAMEPREFIX=	linux-
DISTNAME=	virtual_jay_peak_linux_1_1a

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulation of snowboarding at the Jay Peak resort in Vermont

OPTIONS_DEFINE=	DOCS NVIDIA

WRKSRC=		${WRKDIR}/soulride
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_BUILD=	yes
SUB_FILES=	virtual-jay-peak

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA}
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:x11/nvidia-driver
.else
USE_LINUX_APPS+=	dri
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/virtual-jay-peak ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/soulride-static ${STAGEDIR}${PREFIX}/libexec

	${MKDIR} ${STAGEDIR}${DATADIR}
.for d in Recordings data
	${CP} -R ${WRKSRC}/${d} ${STAGEDIR}${DATADIR}
.endfor

	-${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/*
	${FIND} ${STAGEDIR}${DATADIR}/* -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	${FIND} ${STAGEDIR}${DATADIR}/* -type d -exec ${CHMOD} ${BINMODE} {} \;

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in readme-jay_peak.txt readme-linux.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
