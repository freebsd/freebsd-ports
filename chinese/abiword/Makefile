# New ports collection makefile for:    zh-abiWord
# Date created:		8 March 2001
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abiword
PORTVERSION=	0.7.13
CATEGORIES=	chinese editors
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	AbiWord:${PORTSDIR}/editors/AbiWord \
		ttfm.sh:${PORTSDIR}/chinese/ttfm \
		${LOCALBASE}/share/fonts/TrueType/bkai00mp.ttf:${PORTSDIR}/chinese/arphicttf \
		${LOCALBASE}/share/ghostscript/CJK/CMap/ac13/CMap/Adobe-CNS1-0:${PORTSDIR}/chinese/ghostscript6

NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
