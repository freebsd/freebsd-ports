# New ports collection makefile for:	linux-unace
# Date created:				29 May 2003
# Whom:					fjoe@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	unace
PORTVERSION=	2.20
CATEGORIES=	archivers linux
MASTER_SITES=	http://ace.imptech.net/ \
		http://www.shedz.com/winace/ \
		http://hem.passagen.se/vanlid/winace/ \
		http://ace.edskes.com/winace/ \
		http://www.maxeline.com/winace/
PKGNAMEPREFIX=	linux-
DISTNAME=	linunace22
EXTRACT_SUFX=	.tgz

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Extract, view & test ACE 2 archives

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/unace2
STRIP=

.if exists(/usr/bin/brandelf)
BRANDELF?=	/usr/bin/brandelf
.else
BRANDELF?=	brandelf
.endif

do-patch:
	@${BRANDELF} -t Linux ${WRKSRC}/unace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin/unace2

.include <bsd.port.mk>
