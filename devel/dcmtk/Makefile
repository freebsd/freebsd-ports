# New ports collection Makefile for:	dcmtk
# Date created:				26 July 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	dcmtk
PORTVERSION=	3.5.4
CATEGORIES=	devel
MASTER_SITES=	ftp://dicom.offis.de/pub/dicom/offis/software/${PORTNAME}/${PORTNAME}${PORTVERSION:S/.//g}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A toolkit to work with DICOM files

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
    		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CFLAGS=		-D__BSD_VISIBLE
CPPFLAGS=	${CFLAGS}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libpnginc=${LOCALBASE}/include \
		--with-libtiffinc=${LOCALBASE}/include \
		--with-libxmlinc=${LOCALBASE}/include \
		--bindir=${PREFIX}/bin/${PORTNAME} \
		--sysconfdir=${PREFIX}/etc/${PORTNAME} \
		--datadir=${DATADIR}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" AR="${CXX}" \
		ARFLAGS="-shared -o" LIBEXT="so" RANLIB=":"

INSTALL_TARGET=	install install-lib

SHLIBS=		dcmdata dcmdsig dcmimage dcmimgle dcmjpeg dcmnet \
		dcmpstat dcmqrdb dcmsr dcmtls dcmwlm ijg12 ijg16 \
		ijg8 ofstd
SHLIBVER=	${PORTVERSION:R:R}
PLIST_SUB=	SHLIBVER=${SHLIBVER}

post-install:
.for shlib in ${SHLIBS}
	@${MV} ${PREFIX}/lib/lib${shlib}.so ${PREFIX}/lib/lib${shlib}.so.${SHLIBVER}
	@${LN} -sf ${PREFIX}/lib/lib${shlib}.so.${SHLIBVER} ${PREFIX}/lib/lib${shlib}.so
.endfor

.include "Makefile.man"
.include <bsd.port.mk>

