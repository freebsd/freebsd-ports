# New ports collection makefile for:	mtaserver
# Date created:				25 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	${MTANAME:L}
PORTVERSION=	0.5
CATEGORIES=	games linux
MASTER_SITES=	http://files.gonnaplay.com/201/:main \
		http://www.trancevibez.com/mta/:both \
		http://files.gonnaplay.com/20104/:patch
DISTFILES=	${MTANAME}0_5-linux.tar.gz:main,both ${MTANAME}0_5-linux-patch1.tar.gz:patch,both
DIST_SUBDIR=	mta

MAINTAINER=	ports@logvinov.com
COMMENT=	Multi Theft Auto: Vice City and GTA3 dedicated server

USE_LINUX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_RC_SUBR=	mtad
MTANAME=	MTAServer
FILES=		CHANGELOG LICENSE ${PORTNAME} README banned.lst ${PORTNAME}.conf.dist
PLIST_SUB=	MTADIR="${PORTNAME}"
SUB_FILES=	pkg-message
SUB_LIST=	MTADIR="${PREFIX}/${PORTNAME}"

post-patch:
	@${MV} ${WRKSRC}/${MTANAME} ${WRKSRC}/${PORTNAME}
	@${MV} ${WRKSRC}/${PORTNAME}.conf ${WRKSRC}/${PORTNAME}.conf.dist
	@${CHMOD} 600 ${WRKSRC}/${PORTNAME}.conf.dist

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
.for i in ${FILES}
	@${CP} -p ${WRKSRC}/${i} ${PREFIX}/${PORTNAME}/${i}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
