# New ports collection makefile for:	img
# Date Created:		20 February 1999
# Whom:			Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	libimg
PORTVERSION=	1.2.4
CATEGORIES=	graphics tk83
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/packages-8.0/graphics/Img/1.2/
DISTNAME=	img${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A library of image format handlers for Tk4.1 and later

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83 \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/img${PORTVERSION}

# We don't need the bundled libraries at all, except for a few headers
# from libtiff, see comment in files/Makefile.bsd:
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude '*/libz/*' \
		--exclude '*/compat/*' --exclude '*/libtiff/*.c' \
		--exclude '*/libjpeg/*' --exclude '*/libpng/*'

MAKEFILE=	${FILESDIR}/Makefile.bsd

MAKE_ARGS=	PORTVERSION="${PORTVERSION}" LOCALBASE="${LOCALBASE}" \
		MKDIR="${MKDIR}" INSTALL_DATA="${INSTALL_DATA}"

INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${LOCALBASE}/share/doc/Img1.2
	${INSTALL_DATA} ${WRKSRC}/doc/* ${LOCALBASE}/share/doc/Img1.2
.endif

.include <bsd.port.mk>

PLIST_SUBP!=	${SETENV} TCL_VER=${TCL_VER} ${MAKE} -f ${MAKEFILE} environ
PLIST_SUB+=	${PLIST_SUBP}
