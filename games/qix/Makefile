# New ports collection makefile for:    qix
# Date created:         6 June 2000
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	qix
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

MAINTAINER=	jmz@FreeBSD.org

.if defined(NO_X)
MAKE_ARGS=	NO_X11=yes
.include <bsd.port.pre.mk>
.else
USE_X_PREFIX=	yes
.include <bsd.port.pre.mk>
PLIST=		pkg-plist.x11
.endif
.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

MAN1=		qix.1

FONTSDIR=	lib/X11/fonts/local
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-configure:
	@${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile~
	${SED} -e s:/usr/local:${PREFIX}: -e s:/usr/X11R6:${PREFIX}: \
	  < ${WRKSRC}/Makefile~ > ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
