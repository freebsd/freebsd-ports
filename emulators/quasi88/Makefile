# New ports collection makefile for:	QUASI88
# Date created:		22 May 1999
# Whom:				Nishika <nishika@cheerful.com>
#
# $FreeBSD$
#

PORTNAME=	quasi88
PORTVERSION=	0.4.3
CATEGORIES=	emulators
MASTER_SITES=	http://www.117.ne.jp/~show/pc8801/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nishika@cheerful.com

USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
DATAFILES=	FAQ FORMAT GET-IMAGE HISTORY MANUAL QUASI88 _quasi88rc

.if !defined(WITH_SOUND)
pre-everything::
	@ ${ECHO} "You can make quasi88 use sound by defining WITH_SOUND"
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-aa
.endif

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/quasi88 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/quasi88
.for i in ${DATAFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/quasi88/
.endfor
.endif

.include <bsd.port.mk>
