# New ports collection makefile for:	plasma-kmod
# Date created:				24 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	plasma
PORTVERSION=	0.1
CATEGORIES=	graphics
MASTER_SITES=	http://users.uk.freebsd.org/~greid/
PKGNAMESUFFIX=	-kmod

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plasma-effect screensaver kernel module

.if !exists(/usr/src/sys/dev/syscons/syscons.h)
IGNORE=		"Requires kernel source (/usr/src/sys) to build"
.endif
PLIST_FILES=	lib/plasma_saver.ko

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plasma_saver.ko ${PREFIX}/lib

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
