# New ports collection makefile for:	QUASI88
# Version required:	0.3.2
# Date created:		22 May 1999
# Whom:				Nishika <nishika@cheerful.com>
#
# $FreeBSD$
#

DISTNAME=	quasi88-0.3.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.117.ne.jp/~show/pc8801/
EXTRACT_SUFX=   .tgz

MAINTAINER=	nishika@cheerful.com

USE_X_PREFIX=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
DATAFILES=	FAQ FORMAT GET-IMAGE HELP HISTORY LIST MANUAL QUASI88

pre-patch:
.if !defined(USE_SOUND)
	@ ${ECHO} "You can make quasi88 use sound by defining USE_SOUND"
.else
	@ ${CP} ${FILESDIR}/patch-aa ${PATCHDIR}
.endif

post-patch:
.if defined(USE_SOUND)
	@ ${RM} ${PATCHDIR}/patch-aa
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
