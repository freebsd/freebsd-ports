# ex:ts=8
# New ports collection makefile for:	adgali
# Date created:			Sep 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	adgali
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source game library useful for 2D games programmation

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=	yes
USE_GNOME=	gnometarget
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O3 ||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
