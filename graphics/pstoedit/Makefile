# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.33
PORTREVISION=	4
CATEGORIES=	graphics print
MASTER_SITES=	http://home.t-online.de/home/helga.glunz/wglunz/pstoedit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert PostScript to other vector graphic formats

USE_GHOSTSCRIPT=yes

LIB_DEPENDS=	Magick++.8:${PORTSDIR}/graphics/ImageMagick \
		ming.3:${PORTSDIR}/graphics/ming \
		plotter.4:${PORTSDIR}/graphics/plotutils \
		EMF.1:${PORTSDIR}/graphics/libemf

USE_GNOME=	gnometarget pkgconfig
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--with-libemf-include=${LOCALBASE}/include/libEMF
INSTALLS_SHLIB=	yes

MAN1=	pstoedit.1

CPPFLAGS=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include \
		-I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

pre-everything::
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO_MSG} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||g' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/pstoedit.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changelog.htm ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.htm ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/pstoedit.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
