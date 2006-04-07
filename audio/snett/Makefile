# New ports collection makefile for:	snett
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	snett
PORTVERSION=	0.0.1
CATEGORIES=	audio ruby
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/snett/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	alex@foxybanana.com
COMMENT=	A simple XMMS2 client inspired by strange-quark

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/xmmsclient.so:${PORTSDIR}/audio/ruby-xmms2 \
		${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/rake PREFIX=${PREFIX}/ install

.include <bsd.port.post.mk>
