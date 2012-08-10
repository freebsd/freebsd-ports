# Port makefile for:	openvsp
# Date created:		Apr 10 2012
# Whom:			Fernando Apesteguia <fernando.apesteguia@gmail.com>
#
# $FreeBSD$

PORTNAME=	openvsp
PORTVERSION=	2.1.0
CATEGORIES=	cad
MASTER_SITES=	https://nodeload.github.com/OpenVSP/OpenVSP/tarball/OpenVSP_${PORTVERSION}

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Create a 3D model of an aircraft defined by engineering parameters

BUILD_DEPENDS=	${LOCALBASE}/lib/libopenNURBS.a:${PORTSDIR}/graphics/opennurbs

LIB_DEPENDS+=	fltk:${PORTSDIR}/x11-toolkits/fltk
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/OpenVSP-OpenVSP-fabd23a/src

USE_CMAKE=	yes
USE_DOS2UNIX=	yes
USE_XORG=	xinerama xft
USE_GNOME=	libxml2

PORTEXAMPLES=	*
INSTALL_PORTEXAMPLES=	@(cd ${WRKSRC}/../examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})

PLIST_FILES=	bin/vsp

CFLAGS+=	-I${LOCALBASE}/include/openNURBS

do-fetch:
	if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${FETCH_BINARY} -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${MASTER_SITES}; \
	fi

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vsp/vsp ${PREFIX}/bin
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_PORTEXAMPLES}
.endif

.include <bsd.port.mk>
