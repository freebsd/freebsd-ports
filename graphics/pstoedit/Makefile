# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.32
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	http://home.t-online.de/home/helga.glunz/wglunz/pstoedit/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		gs:${PORTSDIR}/print/ghostscript-gnu
LIB_DEPENDS=	Magick++.5:${PORTSDIR}/graphics/ImageMagick \
		ming.3:${PORTSDIR}/graphics/ming \
		plotter.4:${PORTSDIR}/graphics/plotutils
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig \
		gs:${PORTSDIR}/print/ghostscript-gnu

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=	pstoedit.1

CPPFLAGS=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include \
		-I${X11BASE}/include -fpermissive
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pstoedit.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changelog.htm ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.htm ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pstoedit.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
