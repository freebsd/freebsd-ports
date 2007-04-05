# New ports collection makefile for: otcl
# Date created:		23 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

PORTNAME=	otcl
PORTVERSION=	1.12
DISTVERSIONPREFIX=	src-
CATEGORIES=	lang tcl84 tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	otcl-tclcl

MAINTAINER=	mm@FreeBSD.org
COMMENT=	MIT Object Tcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_TK=		yes
USE_TK_BUILD=	yes

USE_AUTOTOOLS=	autoconf:259
USE_LDCONFIG=	yes

PKGINSTALL=	${PORTSDIR}/lang/tcl84/pkg-install.tclsh
PKGDEINSTALL=	${PORTSDIR}/lang/tcl84/pkg-deinstall.tclsh

.if !defined(NOPORTDOCS)
DOCS=		CHANGES.html README.html TODO.html \
		doc/autoload.html doc/capi.html doc/class.html \
		doc/object.html doc/otcl-paper.ps.gz doc/tutorial.html
PORTDOCS=	${DOCS:S/doc\///}
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+= --with-tcl-ver=${TCL_VER} --with-tk-ver=${TK_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/conf/configure.in.x11

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
