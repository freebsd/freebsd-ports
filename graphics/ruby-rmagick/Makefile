# New ports collection makefile for:	RMagick
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rmagick
PORTVERSION=	1.7.0
PORTREVISION=	2
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/2231/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	RMagick-${PORTVERSION}
DIST_SUBDIR=	ruby

#PATCH_SITES=	http://rubyforge.org/download.php/10/
#PATCHFILES=	RMagick-${PORTVERSION}.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby binding for ImageMagick

BUILD_DEPENDS=	wmf2eps:${PORTSDIR}/graphics/libwmf
LIB_DEPENDS=	Magick.8:${PORTSDIR}/graphics/ImageMagick

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

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

# XXX should be resolved in 1.7.2
.if ${ARCH} == "amd64"
BROKEN=		"Segfaults during build"
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
