# New ports collection makefile for:	urbanterror-data
# Date created:				2007-09-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	urbanterror
PORTVERSION=	4.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.snt.utwente.nl/pub/games/urbanterror/ \
		http://mirror.kickassctf.com/ \
		http://mrsentry.net/release/ \
		http://www.iourt.com/urt${PORTVERSION:S/.//}/
PKGNAMESUFFIX=	-data
DISTNAME=	UrbanTerror_${PORTVERSION:S/.//}_FULL

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Standalone realism based mod originally for Quake III Arena

USE_ZIP=	yes
NO_BUILD=	yes
NO_PACKAGE=	Package will be 715MB; set FORCE_PACKAGE if you really want it
WRKSRC=		${WRKDIR}/UrbanTerror

DATADIR=	${Q3DIR}

.include <bsd.port.pre.mk>

Q3DIR!=		cd ${PORTSDIR}/games/quake3-data && ${MAKE} -V Q3DIR

post-extract:
	@cd ${WRKSRC}/q3ut4 && ${MV} readme${PORTVERSION:S/.//}.txt ..

do-install:
	${MKDIR} ${DATADIR}/q3ut4
	${CP} -r ${WRKSRC}/q3ut4/* ${DATADIR}/q3ut4
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme${PORTVERSION:S/.//}.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
