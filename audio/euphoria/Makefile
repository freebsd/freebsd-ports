# New ports collection makefile for:	euphoria
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	euphoria
PORTVERSION=	20070223
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	XMMS2 GUI frontend written with Enlightenment e17 libraries

BUILD_DEPENDS=	rake:${PORTSDIR}/devel/rubygem-rake \
		edje_cc:${PORTSDIR}/graphics/edje
RUN_DEPENDS=	${SADIR}/edje.so:${PORTSDIR}/graphics/ruby-edje \
		${SADIR}/esmart.so:${PORTSDIR}/graphics/ruby-esmart \
		${SADIR}/evas.so:${PORTSDIR}/graphics/ruby-evas \
		${SADIR}/ecore.so:${PORTSDIR}/devel/ruby-ecore \
		${SADIR}/xmmsclient_ecore.so:${PORTSDIR}/audio/ruby-xmms2-ecore

SADIR=		${RUBY_SITEARCHLIBDIR}

USE_BZIP2=	yes
USE_RUBY=	yes
RUBY_SHEBANG_FILES=	${WRKSRC}/bin/euphoria

.include <bsd.port.pre.mk>
.if ${ARCH} == "ia64"
BROKEN=		edje is broken on ia64
.endif

do-build:
	@(cd ${WRKSRC}; ${LOCALBASE}/bin/rake)

do-install:
	@(cd ${WRKSRC}; ${LOCALBASE}/bin/rake install)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
