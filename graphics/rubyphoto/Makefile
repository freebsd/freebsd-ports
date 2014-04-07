# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	rubyphoto
PORTVERSION=	1.4
PORTREVISION=	6
CATEGORIES=	graphics ruby www
MASTER_SITES=	http://www.markhj.com/rubyphoto/files/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	program for creating web image galleries

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		${RUBY_SITELIBDIR}/image_size.rb:${PORTSDIR}/graphics/ruby-image_size \
		${RUBY_SITELIBDIR}/xml/parser.rb:${PORTSDIR}/textproc/ruby-xmlparser

NO_BUILD=	yes

USE_RUBY=	yes
RUBY_SHEBANG_FILES=	ruby_photo.rb
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/abspath.rb ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/findbin.rb ${STAGEDIR}${RUBY_SITELIBDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/sample_input
	@${MKDIR} ${STAGEDIR}${DATADIR}/templates/alternate
	@${MKDIR} ${STAGEDIR}${DATADIR}/swigs-converters
	@${MKDIR} ${STAGEDIR}${DATADIR}/xml-generators
	${INSTALL_DATA} ${WRKSRC}/COPYING ${WRKSRC}/README.html \
		${WRKSRC}/album.rb ${WRKSRC}/config.rb ${WRKSRC}/dyn_resize.rb \
		${WRKSRC}/image_cat.rb ${WRKSRC}/image_size_cache.rb \
		${WRKSRC}/joke.rb ${WRKSRC}/myxml.rb ${WRKSRC}/photo.rb \
		${WRKSRC}/rp_debug.rb ${WRKSRC}/ruby_photo.rb \
		${WRKSRC}/template.rb ${WRKSRC}/urlencode.rb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample_input/* ${STAGEDIR}${DATADIR}/sample_input
	${INSTALL_DATA} ${WRKSRC}/templates/album.xml ${WRKSRC}/templates/image.xml \
		${WRKSRC}/templates/shared.xml ${WRKSRC}/templates/tree.xml \
		${STAGEDIR}${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/alternate/* ${STAGEDIR}${DATADIR}/templates/alternate
	${INSTALL_DATA} ${WRKSRC}/swigs-converters/* ${STAGEDIR}${DATADIR}/swigs-converters
	${INSTALL_DATA} ${WRKSRC}/xml-generators/* ${STAGEDIR}${DATADIR}/xml-generators

.include <bsd.port.mk>
