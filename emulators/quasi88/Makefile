# New ports collection makefile for:	QUASI88
# Version required:	0.2.4
# Date created:		22 May 1999
# Whom:				Nishika <nishika@cheerful.com>
#
# $FreeBSD$
#

DISTNAME=	quasi88-0.2.4
CATEGORIES=	emulators
MASTER_SITES=	http://www.117.ne.jp/~show/pc8801/
EXTRACT_SUFX=   .tgz

MAINTAINER=	nishika@cheerful.com

USE_XLIB=	yes
DATAFILES=	FAQ FILES FORMAT GET-IMAGE HELP HISTORY LIST MANUAL QUASI88

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/quasi88 ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/doc/quasi88

.for i in ${DATAFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/quasi88/
.endfor

.include <bsd.port.mk>
