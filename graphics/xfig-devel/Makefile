# New ports collection makefile for:	xfig
# Version required:	3.2.2
# Date created:		4 January 1995
# Whom:			roberto
#
# $FreeBSD$
#

DISTNAME=	xfig.3.2.2
PKGNAME=	xfig-3.2.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/xfig

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

.if defined(WANT_GS_SUPPORT)
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript5
.endif

USE_IMAKE=	yes
MAN1=		xfig.1

pre-fetch:
.if !defined(WANT_GS_SUPPORT)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you would like build xfig with Ghostscript support"
	@${ECHO_MSG} "you must set the variable WANT_GS_SUPPORT"
	@${ECHO_MSG} ""
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Building xfig with Ghostscript support"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Imakefile
.if !defined(WANT_GS_SUPPORT)
	@${PERL} -pi -e 's|-DGSBIT ||g' ${WRKSRC}/Imakefile
.endif

.include <bsd.port.mk>
