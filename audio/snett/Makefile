# New ports collection makefile for:	snett
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	snett
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	audio ruby
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/snett/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	A simple XMMS2 client inspired by strange-quark

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmmsclient.so:${PORTSDIR}/audio/ruby-xmms2 \
		${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RAKE=	yes
NO_BUILD=	yes

BROKEN=	Not updated to the DrJekyll clientlib API
do-install:
	@cd ${WRKSRC} && ${RAKE_BIN} PREFIX=${PREFIX}/ ${INSTALL_TARGET}

.include <bsd.port.mk>
