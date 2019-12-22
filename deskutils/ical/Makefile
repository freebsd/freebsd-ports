# Created by: Eric L. Hernes <erich@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ical
PORTVERSION=	2.2
PORTREVISION=	5
CATEGORIES=	deskutils tk
MASTER_SITES=	http://opal.com/jr/ical/

PATCH_SITES=	http://www.isi.edu/~johnh/SOFTWARE/ICAL/
PATCHFILES=	ical-2.3.1-upvar.patch

MAINTAINER=	fbsd@opal.com
COMMENT=	Calendar application

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		tk xorg
USE_XORG=	x11 xext xft xrender xscrnsaver
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${TCL_LIBDIR} \
		--with-tclhdir=${TCL_INCLUDEDIR} \
		--with-tclsh=${TCLSH} \
		--with-tkconfig=${TK_LIBDIR} \
		--with-tkhdir=${TK_INCLUDEDIR}
MAKE_ENV=	STAGEDIR=${STAGEDIR}

post-patch:
	@${REINPLACE_CMD} -e 's,tcl->result,Tcl_GetStringResult(tcl),' \
		${WRKSRC}/ical.C

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
