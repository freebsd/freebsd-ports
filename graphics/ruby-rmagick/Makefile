# New ports collection makefile for:	RMagick
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rmagick
PORTVERSION=	1.4.0
CATEGORIES=	graphics ruby
MASTER_SITES=	http://rubyforge.org/download.php/352/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	RMagick-${PORTVERSION}
DIST_SUBDIR=	ruby

#PATCH_SITES=	http://rubyforge.org/download.php/10/
#PATCHFILES=	RMagick-${PORTVERSION}.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby binding for ImageMagick

LIB_DEPENDS=	Magick.6:${PORTSDIR}/graphics/ImageMagick

BROKEN=		"Does not compile"

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb


CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		RUBY="${RUBY}"
CONFIGURE_ARGS=	--doc-dir="${RUBY_MODDOCDIR}"

DOCS=		ChangeLog README.html

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

.include <bsd.port.mk>
