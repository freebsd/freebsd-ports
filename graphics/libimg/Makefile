# New ports collection makefile for:	img
# Date Created:		20 February 1999
# Whom:			Glenn Johnson
#
# $FreeBSD$
#

PORTNAME=	libimg
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	graphics tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tkimg
DISTNAME=	img${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of image format handlers for Tk4.1 and later

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84 \
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
