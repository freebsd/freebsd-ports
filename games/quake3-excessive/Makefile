# New ports collection makefile for:	Q3 Mod: Excessive
# Date created:				Sat Jun 23 23:40:21 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	excessive
PORTVERSION=	003
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pat
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_q3_server_${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake III Arena Mod: Excessive

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	yes
USE_CRLF=	yes
NO_BUILD=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

post-extract:
	@(cd ${WRKSRC}; ${UNZIP_CMD} description.pk3)

do-install:
	@${MKDIR} ${DATADIR}
.for f in description.txt motd.cfg maplist.cfg
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
	@${MKDIR} ${DATADIR}/vm
	@${INSTALL_DATA} ${WRKSRC}/vm/qagame.qvm ${DATADIR}/vm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.mk>
