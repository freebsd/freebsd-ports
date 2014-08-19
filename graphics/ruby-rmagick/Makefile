# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rmagick
PORTVERSION=	2.13.2
CATEGORIES=	graphics ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	RMagick-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby binding for ImageMagick

USES=		pkgconfig tar:bzip2
BROKEN=		not staged

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11

OPTIONSFILE?=	${PORT_DBDIR}/ruby-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS=	libMagickWand-6.Q*.so:${PORTSDIR}/graphics/ImageMagick
.else
LIB_DEPENDS=	libMagickWand-6.Q*.so:${PORTSDIR}/graphics/ImageMagick-nox11
.endif

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	setup.rb

CONFIGURE_ENV=	RUBY="${RUBY}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--doc-dir="${RUBY_MODDOCDIR}" --prefix="${PREFIX}" \
		--allow-example-errors
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-htmldoc
.endif

DOCS=		ChangeLog README.html

DEPRECATED=	RubyForge shutdown May 15 2014
EXPIRATION_DATE=	2014-09-20

.include <bsd.port.pre.mk>

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
