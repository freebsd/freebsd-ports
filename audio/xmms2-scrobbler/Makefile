# New ports collection makefile for:	xmms2-scrobbler
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	xmms2-scrobbler
PORTVERSION=	0.1.2
CATEGORIES=	audio ruby
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/xmms2-scrobbler/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	A last.fm submission client for XMMS2

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmmsclient.so:${PORTSDIR}/audio/ruby-xmms2 \
		${RUBY_SITELIBDIR}/event-loop.rb:${PORTSDIR}/devel/ruby-event-loop \
		${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmmsclient.so:${PORTSDIR}/audio/ruby-xmms2 \
		${RUBY_SITELIBDIR}/event-loop.rb:${PORTSDIR}/devel/ruby-event-loop

USE_RUBY=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/xmms2-scrobbler

SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/rake PREFIX=${PREFIX}/ ${INSTALL_TARGET}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
