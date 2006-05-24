# New ports collection makefile for:	RMagick
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rmagick
PORTVERSION=	1.9.3
PORTREVISION=	2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.lauschmusik.de/rmagick/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	RMagick-${PORTVERSION}
DIST_SUBDIR=	ruby
OPTIONSFILE?=	${PORT_DBDIR}/${DIST_SUBDIR}-${PORTNAME}/options

#PATCH_SITES=	http://rubyforge.org/download.php/10/
#PATCHFILES=	RMagick-${PORTVERSION}.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby binding for ImageMagick

OPTIONS= GRAPHICSMAGICK "Use GraphicsMagick instead of ImageMagick" Off

BUILD_DEPENDS=	wmf2eps:${PORTSDIR}/graphics/libwmf

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -I${X11BASE}/lib" \
		RUBY="${RUBY}"
CONFIGURE_ARGS=	--doc-dir="${RUBY_MODDOCDIR}"

DOCS=		ChangeLog README.html

.include <bsd.port.pre.mk>

.if defined(WITH_GRAPHICSMAGICK)
LIB_DEPENDS=GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick
.else
LIB_DEPENDS=Magick.10:${PORTSDIR}/graphics/ImageMagick
.endif

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

pre-configure:
	cd ${CONFIGURE_WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ./configure --prefix="${PREFIX}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
