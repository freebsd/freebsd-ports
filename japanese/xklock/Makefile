# New ports collection makefile for:	xklock
# Date created:		20 April 1997
# Whom:			nkazushi@highway.or.jp
#
# $FreeBSD$
#

PORTNAME=	xklock
PORTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}+lx.diff.gz
PATCH_DIST_STRIP=	-p1

FORBIDDEN=	"Exploitable buffer overflows"

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

pre-configure:
.for file in jnames.c xklock.h
	@${PERL} -pi -e "s:%%PREFIX%%:${PREFIX}:" ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} -m 4755 ${WRKSRC}/xklock ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/xklock
	${TOUCH} ${PREFIX}/lib/X11/xklock/jnames

.include <bsd.port.mk>
