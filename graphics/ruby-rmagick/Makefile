# New ports collection makefile for:	RMagick
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rmagick
PORTVERSION=	0.9.5
CATEGORIES=	graphics ruby
MASTER_SITES=	http://home.nc.rr.com/rmagick/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	RMagick-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	Magick.5:${PORTSDIR}/graphics/ImageMagick

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		RUBY="${RUBY}"

DOCS=		ChangeLog README.txt

post-patch:
	${REINPLACE_CMD} 's:/RMagick:/doc/${RUBY_NAME}/${RUBY_MODNAME}&:' ${WRKSRC}/post-install.rb

pre-configure:
	cd ${CONFIGURE_WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ./configure --prefix="${PREFIX}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
