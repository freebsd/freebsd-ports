# New ports collection makefile for:	etpub
# Date created:				7 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	etpub
PORTVERSION=	0.6.5
CATEGORIES=	games linux
MASTER_SITES=	http://et.tjw.org/etpub/dist/
PKGNAMEPREFIX=	linux-enemyterritory-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${CLIENT_PK3}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	ET Pub - An Enemy Territory Modification

RUN_DEPENDS=	et:${PORTSDIR}/games/linux-enemyterritory

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_LINUX=	yes

DATADIR=	${PREFIX}/lib/enemyterritory/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/enemyterritory-${PORTNAME}

CLIENT_PK3=	${PORTNAME}_client-20060310.pk3
PLIST_SUB=	CLIENT_PK3="${CLIENT_PK3}"

pre-patch:
	@${FIND} ${WRKSRC} -type f -exec ${SH} -c \
		'${FILE} "$$0" | ${GREP} -q text && \
		${REINPLACE_CMD} -i "" -e "s/$$//" "$$0"' {} \;

do-build:
.for f in et etded
	@(${ECHO} "#!/bin/sh"; \
	${ECHO} 'exec ${PREFIX}/bin/${f} +set fs_game ${PORTNAME} "$$@"') > \
		${WRKSRC}/${f}-${PORTNAME}
.endfor

do-install:
.for f in et etded
	${INSTALL_SCRIPT} ${WRKSRC}/${f}-${PORTNAME} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/glibc-2.1/qagame.mp.i386.so ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${CLIENT_PK3} ${DATADIR}
	${CP} -R ${WRKSRC}/extra ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.   for f in ChangeLog.txt Install.txt Upgrade-0.6.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
	${CP} -R ${WRKSRC}/docs ${DOCSDIR}
.endif

.include <bsd.port.mk>
