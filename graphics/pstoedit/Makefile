# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.32
CATEGORIES=	graphics print
MASTER_SITES=	http://home.t-online.de/home/helga.glunz/wglunz/pstoedit/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu
LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming \
		plot.4:${PORTSDIR}/graphics/plotutils \
		plotter.4:${PORTSDIR}/graphics/plotutils
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

MAN1=	pstoedit.1

CPPFLAGS=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include \
		-I${X11BASE}/include -fpermissive
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pstoedit.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
