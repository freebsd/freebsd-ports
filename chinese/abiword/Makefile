# New ports collection makefile for:    zh-abiWord
# Date created:		8 March 2001
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abiword
PORTVERSION=	1.0.3
CATEGORIES=	chinese editors
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross-platform WYSIWYG word processor, with BIG5/GB available

RUN_DEPENDS=	AbiWord-2.0:${PORTSDIR}/editors/AbiWord2 \
		ttfm.sh:${PORTSDIR}/chinese/ttfm \
		${LOCALBASE}/share/fonts/TrueType/bkai00mp.ttf:${PORTSDIR}/chinese/arphicttf

NO_BUILD=	yes
USE_X_PREFIX=	yes
USE_GHOSTSCRIPT_RUN=	yes

.include <bsd.port.pre.mk>

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

do-install:
	@${SETENV} PKG_PREFIX=${LOCALBASE} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
