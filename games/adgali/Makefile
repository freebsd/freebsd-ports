# ex:ts=8
# New ports collection makefile for:	adgali
# Date created:			Sep 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	adgali
PORTVERSION=	0.2.4
PORTREVISION=	6
CATEGORIES=	games devel
MASTER_SITES=	http://adgali.apiou.org/download/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	An open source game library useful for 2D game development

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_SDL=	sdl
USE_XORG=	xpm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lexecinfo"
CONFIGURE_ARGS=	--enable-compile-optim=no
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Configure fails
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
