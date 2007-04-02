# New ports collection makefile for:	RMagick
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rmagick
PORTVERSION=	1.15.5
PORTREVISION=	0
CATEGORIES=	graphics ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	RMagick-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A Ruby binding for ImageMagick

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	setup.rb

CONFIGURE_ENV=	CFLAGS="${CFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -I${X11BASE}/lib" \
		RUBY="${RUBY}"
CONFIGURE_ARGS=	--doc-dir="${RUBY_MODDOCDIR}" --prefix="${PREFIX}"
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-htmldoc
.endif

OPTIONSFILE?=	${PORT_DBDIR}/${DIST_SUBDIR}-${PORTNAME}/options

OPTIONS=	GRAPHICSMAGICK "Use GraphicsMagick instead of ImageMagick" Off

DOCS=		ChangeLog README.html

.include <bsd.port.pre.mk>

.if defined(WITH_GRAPHICSMAGICK)
LIB_DEPENDS+=	GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick
.else
LIB_DEPENDS+=	Magick.10:${PORTSDIR}/graphics/ImageMagick
.endif

pre-configure:
	cd ${CONFIGURE_WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ./configure --prefix="${PREFIX}"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	@${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
#
# Files installed in /ex may vary over different archs
#
	@${FIND} ${RUBY_MODDOCDIR}/ex/ ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_MODDOCDIR}/ex/ -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${RUBY_MODDOCDIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
