# New ports collection makefile for:	ghostscript
# Date created:		14 Jan 2002
# Whom:			Mita Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghostscript-gnu-korfont
PORTVERSION=	7.07
PORTREVISION=	3
CATEGORIES=	korean print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Korean font support for GNU Ghostscript

RUN_DEPENDS=	${LOCALBASE}/share/fonts/CIDFont/Munhwa-Regular:${PORTSDIR}/korean/munhwafonts-cid \
		${LOCALBASE}/share/ghostscript/Resource/CIDFont/HYSMyeongJo-Medium:${PORTSDIR}/print/ghostscript-gnu-commfont

# set these forcibly
WITH_GHOSTSCRIPT_GNU=	yes
USE_GHOSTSCRIPT_RUN=	yes
NO_BUILD=	yes
DEPENDS_ARGS+=	-DA4

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
