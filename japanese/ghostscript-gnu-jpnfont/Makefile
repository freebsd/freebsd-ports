# New ports collection makefile for:	ghostscript
# Date created:		14 Jan 2002
# Whom:			Mita Yoshio <mita@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghostscript-gnu-jpnfont
PORTVERSION=	7.07
PORTREVISION=	4
CATEGORIES=	japanese print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese font support for GNU Ghostscript

RUN_DEPENDS=	${LOCALBASE}/share/fonts/TrueType/ipam.ttf:${PORTSDIR}/japanese/ipa-ttfonts \
		${LOCALBASE}/share/ghostscript/Resource/CIDFont/Ryumin-Light:${PORTSDIR}/print/ghostscript-gnu-commfont

# set these forcibly
WITH_GHOSTSCRIPT_GNU=   yes
USE_GHOSTSCRIPT_RUN=    yes
NO_BUILD=       yes
DEPENDS_ARGS+=	-DA4

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
