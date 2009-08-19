# New ports collection makefile for:	xmms2-scrobbler
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	xmms2-scrobbler
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	audio ruby
MASTER_SITES=	http://exodus.xmms.se/~tilman/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A last.fm submission client for XMMS2

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmmsclient_ext.so:${PORTSDIR}/audio/ruby-xmms2 \
		${RUBY_SITELIBDIR}/event-loop.rb:${PORTSDIR}/devel/ruby-event-loop
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmmsclient_ext.so:${PORTSDIR}/audio/ruby-xmms2 \
		${RUBY_SITELIBDIR}/event-loop.rb:${PORTSDIR}/devel/ruby-event-loop

USE_RUBY=	yes
USE_RAKE=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/xmms2-scrobbler \
		%%DATADIR%%/filters/britney.rb \
		%%DATADIR%%/filters/musicbrainz.rb
PLIST_DIRS=	%%DATADIR%%/filters %%DATADIR%%

SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC} && ${RAKE_BIN} PREFIX=${PREFIX}/ ${INSTALL_TARGET}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
