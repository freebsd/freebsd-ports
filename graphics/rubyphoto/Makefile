# New ports collection makefile for:	rubyphoto
# Date created:			June 14, 2003
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	rubyphoto
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	graphics ruby www
MASTER_SITES=	http://www.markhj.com/rubyphoto/files/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A program for creating web image galleries

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		${RUBY_SITELIBDIR}/image_size.rb:${PORTSDIR}/graphics/ruby-image_size \
		${RUBY_SITELIBDIR}/xml/parser.rb:${PORTSDIR}/textproc/ruby-xmlparser

NO_BUILD=	yes

USE_RUBY=	yes
RUBY_SHEBANG_FILES=	ruby_photo.rb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abspath.rb ${RUBY_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/findbin.rb ${RUBY_SITELIBDIR}
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/sample_input
	@${MKDIR} ${DATADIR}/templates
	@${MKDIR} ${DATADIR}/templates/alternate
	@${MKDIR} ${DATADIR}/swigs-converters
	@${MKDIR} ${DATADIR}/xml-generators
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/album.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dyn_resize.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/image_cat.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/image_size_cache.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/joke.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/myxml.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/photo.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/rp_debug.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ruby_photo.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/template.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/urlencode.rb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample_input/* ${DATADIR}/sample_input
	${INSTALL_DATA} ${WRKSRC}/templates/album.xml ${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/image.xml ${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/shared.xml ${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/tree.xml ${DATADIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/alternate/* ${DATADIR}/templates/alternate
	${INSTALL_DATA} ${WRKSRC}/swigs-converters/* ${DATADIR}/swigs-converters
	${INSTALL_DATA} ${WRKSRC}/xml-generators/* ${DATADIR}/xml-generators

post-install:
	@${SED} -e "s#%%DATADIR%%#${DATADIR}#" ${PKGMESSAGE}

.include <bsd.port.mk>
