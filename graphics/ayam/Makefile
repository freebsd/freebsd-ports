# New ports collection makefile for: ayam
# Date created:		19 Apr 2003
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	ayam
PORTVERSION=	1.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	tiamat@comset.net
COMMENT=	3D modeling environment for the RenderMan interface

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GL=		yes
USE_XLIB=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src
MAKEFILE=	Makefile.shared

AYAM_PLUGINS=	csphere mfio

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/tcl/ayam.tcl

do-install:
# binary and wrapper
	${INSTALL_PROGRAM} ${WRKSRC}/ayamsh ${PREFIX}/bin
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} "${PREFIX}/bin/ayamsh ${PREFIX}/lib/ayam/tcl/ayam.tcl \$$@" \
	) >${PREFIX}/bin/ayam
	@${CHMOD} ugo+x ${PREFIX}/bin/ayam

# plugins
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for i in ${AYAM_PLUGINS}
	${INSTALL_DATA} ${WRKSRC}/plugins/${i}.tcl \
		${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/${i}.so \
		${PREFIX}/lib/${PORTNAME}
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/meta/*.tcl ${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/meta/metaobj.so ${PREFIX}/lib/${PORTNAME}

# tcl libs
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/tcl
	${INSTALL_DATA} ${WRKSRC}/tcl/*.tcl ${PREFIX}/lib/${PORTNAME}/tcl
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/tcl/BWidget-1.2.1
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/*.tcl \
		${PREFIX}/lib/${PORTNAME}/tcl/BWidget-1.2.1
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/tcl/BWidget-1.2.1/images
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/images/* \
		${PREFIX}/lib/${PORTNAME}/tcl/BWidget-1.2.1/images
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}/tcl/BWidget-1.2.1/lang
	${INSTALL_DATA} ${WRKSRC}/tcl/BWidget-1.2.1/lang/* \
		${PREFIX}/lib/${PORTNAME}/tcl/BWidget-1.2.1/lang

# data
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/lib/ayam-splash.gif ${DATADIR}

# docs
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/refcard.ps ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/html/*.html ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/html/pics
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/doc/html/pics/* \
		${DOCSDIR}/html/pics
.endif

.include <bsd.port.mk>
