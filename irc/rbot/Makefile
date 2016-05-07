# Created by: David Bushong <david+ports@bushong.net>
# $FreeBSD$

PORTNAME=	rbot
PORTVERSION=	20150311
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	irc ruby

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Ruby IRC bot similar to infobot

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/tokyocabinet.so:databases/ruby-tokyocabinet \
		rubygem-mechanize>=0:www/rubygem-mechanize \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-oauth>=0:net/rubygem-oauth \
		rubygem-oauth2>=0:net/rubygem-oauth2
LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	ruby-${PORTNAME}
GH_TAGNAME=	545f21791ad804a52f6b7470403a1fa5a3976f5f

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

PORTDOCS=	REQUIREMENTS ChangeLog

OPTIONS_DEFINE=	DOCS

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
