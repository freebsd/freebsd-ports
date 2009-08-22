# New ports collection makefile for: otcl
# Date created:		23 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	otcl
PORTVERSION=	1.13
PORTREVISION=	3
DISTVERSIONPREFIX=	src-
CATEGORIES=	lang tcl tk
MASTER_SITES=	SF/${PORTNAME}-tclcl/OTcl/${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	MIT Object Tcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_TK=		82+
USE_TK_NO_THREADS=	yes
INVALID_TK_VER=	85 86
USE_XORG=	xext

USE_AUTOTOOLS=	autoconf:262
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
DOCS=		CHANGES.html README.html \
		doc/autoload.html doc/capi.html doc/class.html \
		doc/object.html doc/otcl-paper.ps.gz doc/tutorial.html
PORTDOCS=	${DOCS:S/doc\///}
.endif

.include <bsd.port.pre.mk>

CFLAGS+=	-DHAVE_UNISTD_H
CONFIGURE_ARGS+=	--with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e's|X11/Intrinsic.h|X11/Xlib.h|g' \
		${WRKSRC}/configure ${WRKSRC}/conf/configure.in.x11
	@${REINPLACE_CMD} -e 's|../lib/tcl$$TCL_HI_VERS|${TCL_LIBDIR}|g' \
		-e 's|../include|${TCL_INCLUDEDIR}/generic|g' \
		${WRKSRC}/conf/configure.in.tcl
	@${REINPLACE_CMD} -e 's|../lib/tk$$TK_HI_VERS|${TK_LIBDIR}|g' \
		-e 's|../include|${TK_INCLUDEDIR}/generic|g' \
		${WRKSRC}/conf/configure.in.tk

post-install:
	${LN} -sf libotcl.so ${PREFIX}/lib/libotcl.so.1
	${STRIP_CMD} ${PREFIX}/bin/otclsh
	${STRIP_CMD} ${PREFIX}/bin/owish
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
