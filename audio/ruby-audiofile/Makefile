# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	audiofile
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	audio ruby
MASTER_SITES=	SF/ruby-${PORTNAME}/ruby-${PORTNAME}/${PORTVERSION}:audiofile \
		SF/ruby-${PORTNAME}/cddb/${CDDB_VER}:cddb
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:audiofile \
		cddb-${CDDB_VER}${EXTRACT_SUFX}:cddb
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding to the audiofile library

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CDDB_VER=	0.2
CDDB_WRKSRC=	${WRKDIR}/example

INSTALL_TARGET=	site-install
REINPLACE_ARGS=	-i ""

DEPRECATED=	Broken on modern versions of Ruby
EXPIRATION_DATE=	2017-01-28

post-patch:
	@${REINPLACE_CMD} -E -e "s,/home/jaredj/ruby-lib/(cddb),\1,g" ${CDDB_WRKSRC}/wavcddb

post-install:
	${STRIP_CMD} ${STAGEDIR}${RUBY_SITEARCHLIBDIR}/audiofile.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/audiofile.rd ${STAGEDIR}${RUBY_MODDOCDIR}/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/cddb/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${CDDB_WRKSRC}/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/cddb/

.include <bsd.port.mk>
