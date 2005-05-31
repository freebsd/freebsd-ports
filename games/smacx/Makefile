# New ports collection makefile for:	sid meier's alpha centauri
# Date created:				29 October 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	smacx
PORTVERSION=	1.0
CATEGORIES=	games linux
MASTER_SITES=	ftp://download.linuxlords.com/pub/demos/smac/ \
		ftp://ftp.linux.tucows.com/pub/Loki/demos/smac/ \
		ftp://ftp.linuxgames.com/loki/demos/smac/
DISTNAME=	${PORTNAME}-demo-x86
EXTRACT_SUFX=	.run

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free demo of Sid Meier's Alpha Centauri

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
LINESKIP=	170
EXTRACT_CMD=	tail
EXTRACT_BEFORE_ARGS=	+${LINESKIP}
EXTRACT_AFTER_ARGS=	| ${TAR} -xzf -
STRIP=

do-install:
	${MKDIR} ${PREFIX}/games/smacx
.for SUBDIR in fonts facs fx projs techs
	${MKDIR} ${PREFIX}/games/smacx/data/${SUBDIR}
	${INSTALL_DATA} ${WRKSRC}/data/${SUBDIR}/* ${PREFIX}/games/smacx/data/${SUBDIR}
.endfor
	cd ${WRKSRC} && ${FIND} data -maxdepth 1 -type f > datafiles
	cd ${WRKSRC} && ${INSTALL_DATA} `cat datafiles` ${PREFIX}/games/smacx/data/
.for FILE in QuickStart.txt README icon.xpm
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/games/smacx
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/smacx_demo ${PREFIX}/games/smacx/smacx
	brandelf -t Linux ${PREFIX}/games/smacx/smacx
	${LN} -sf ${PREFIX}/games/smacx/smacx ${PREFIX}/bin/smacx

.include <bsd.port.mk>
