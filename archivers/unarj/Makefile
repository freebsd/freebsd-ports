# New ports collection makefile for:    unarj
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	unarj
PORTVERSION=	2.65
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ache
EXTRACT_SUFX=	.tgz

MAINTAINER=	ache@FreeBSD.org
COMMENT=	Allows files to be extracted from ARJ archives

post-patch:
	${CP} ${FILESDIR}/sanitize.c ${WRKSRC}

do-install:
	${INSTALL} -d -m 755 -o ${SHAREOWN} -g ${SHAREGRP} \
		${PREFIX}/share/doc/unarj
	cd ${WRKSRC}; ${INSTALL_PROGRAM} unarj ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} unarj.txt technote.txt \
		${PREFIX}/share/doc/unarj

.include <bsd.port.mk>
