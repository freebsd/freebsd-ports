# New ports collection makefile for:	Ayam
# Date created:				19 Apr 2003
# Whom:					Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ayam
PORTVERSION=	1.15.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	3D modeling environment for the RenderMan interface

LIB_DEPENDS=	aqsis.1:${PORTSDIR}/graphics/aqsis \
		tk84.1:${PORTSDIR}/x11-toolkits/tk84 \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_XORG=	xmu xext x11
USE_GL=		yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	Makefile.shared
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

AYAM_PLUGINS=	csphere mfio
PLUGINS_DIR=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not build on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/tcl/ayam.tcl
	@${REINPLACE_CMD} -e 's|^MF3DCFLAGS =|MF3DCFLAGS = -fPIC|g' \
		${WRKSRC}/MF3D/Makefile.mf3d

do-install:
# binary and wrapper
	${INSTALL_PROGRAM} ${WRKSRC}/ayamsh ${PREFIX}/bin
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} "${PREFIX}/bin/ayamsh ${PLUGINS_DIR}/tcl/ayam.tcl \$$@" \
	) >${PREFIX}/bin/ayam
	@${CHMOD} ugo+x ${PREFIX}/bin/ayam

# plugins
	@${MKDIR} ${PLUGINS_DIR}
.for i in ${AYAM_PLUGINS}
	${INSTALL_DATA} ${WRKSRC}/plugins/${i}.tcl ${PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/${i}.so ${PLUGINS_DIR}
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/ayslx.so ${PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/plugins/loadayslx.tcl ${PLUGINS_DIR}

	${INSTALL_DATA} ${WRKSRC}/contrib/meta/*.tcl ${PLUGINS_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/meta/metaobj.so ${PLUGINS_DIR}

# tcl libs
	@${MKDIR} ${PLUGINS_DIR}/tcl
	${INSTALL_DATA} ${WRKSRC}/tcl/*.tcl ${PLUGINS_DIR}/tcl
	@${MKDIR} ${PLUGINS_DIR}/tcl/BWidget-1.2.1
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/*.tcl \
		${PLUGINS_DIR}/tcl/BWidget-1.2.1
	@${MKDIR} ${PLUGINS_DIR}/tcl/BWidget-1.2.1/images
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/images/* \
		${PLUGINS_DIR}/tcl/BWidget-1.2.1/images
	@${MKDIR} ${PLUGINS_DIR}/tcl/BWidget-1.2.1/lang
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/lang/* \
		${PLUGINS_DIR}/tcl/BWidget-1.2.1/lang

# data
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/lib/ayam-splash.gif ${DATADIR}

# docs
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/Setup.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/ayam.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/refcard.ps ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/refcard.tcl ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/html/*.html ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/html/pics
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/html/pics/* \
		${DOCSDIR}/html/pics
.endif

.include <bsd.port.post.mk>
