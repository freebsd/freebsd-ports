# New ports collection makefile for:	oneko-sakura
# Date created:		25 May 1999
# Whom:			HOTARU-YA <hotaru@tail.net>
#
# $FreeBSD$
#

PORTNAME=	oneko
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://riksun.riken.go.jp/archives/Linux/pje/PJE-0.1.5/sources/xclt/oneko/ \
		http://hp.vector.co.jp/authors/VA004959/oneko/
PKGNAMESUFFIX=	-sakura5

PATCH_SITES=	http://www.daidouji.com/oneko/distfiles/
PATCHFILES=	oneko-1.2.sakura.5.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hotaru@tail.net
COMMENT=	A cat, Sakura or Tomoyo chasing a mouse all over the screen

USE_IMAKE=	yes
USE_REINPLACE=	yes
MAN6=		oneko.6
PLIST_FILES=	bin/oneko
NO_CDROM=	"Including derivatives from CARDCAPTOR SAKURA. See http://www.clamp.f-2.co.jp/"
RESTRICTED_FILES=	${PATCHFILES}

pre-patch:
	@${REINPLACE_CMD} -e 's,/\*\*/# Cannot compile in using Gcc,/* Cannot compile using Gcc */,' \
	${WRKSRC}/Imakefile

pre-configure:
	@${ECHO_CMD} "MANSUFFIX=6" >>${WRKSRC}/Imakefile

.include <bsd.port.mk>
