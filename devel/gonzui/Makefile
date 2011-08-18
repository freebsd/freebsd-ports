# New ports collection makefile for:	gonzui
# Date created:	Wed Dec  1 16:35:00 GMT 2004
# Whom:		sumikawa
#
# $FreeBSD$
#

PORTNAME=	gonzui
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	A source code search engine

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv \
		${RUBY_SITELIBDIR}/langscan.rb:${PORTSDIR}/devel/ruby-langscan

USE_RUBY=	yes
GNU_CONFIGURE=	yes

RUBY_SHEBANG_FILES=	gonzui-db gonzui-import gonzui-remove \
			gonzui-search gonzui-server gonzui-update

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN= does not build with ruby 1.9
.endif

post-configure:
	${REINPLACE_CMD} -e 's| langscan | |' \
			 -e 's| langscan.*\.rb||' \
			 ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
