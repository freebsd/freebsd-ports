# New ports collection makefile for:	urbanterror-data
# Date created:				2007-09-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	4.1.1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.snt.utwente.nl/pub/games/urbanterror/full_install/linux_or_mac/ \
		http://www.iourt.com/files/ \
		http://urbanterror.mtc-team.fr/
PKGNAMEPREFIX=	urbanterror-
DISTNAME=	UrbanTerror${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.zip
EXTRACT_ONLY=

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Standalone realism based mod originally for Quake III Arena

NO_BUILD=	yes
NO_PACKAGE=	Package will be 1GB; set FORCE_PACKAGE if you really want it

DATADIR=	${PREFIX}/share/quake3

do-install:
	${MKDIR} ${DATADIR}/q3ut4
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTFILES} \
		${EXTRACT_AFTER_ARGS} -C ${DATADIR} --strip-components 1 \
		UrbanTerror/q3ut4
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MV} ${DATADIR}/q3ut4/readme${PORTVERSION:S/.//:C/\..*//}.txt \
		${DOCSDIR}/readme${PORTVERSION:S/.//g}.txt
.else
	${RM} ${DATADIR}/q3ut4/readme${PORTVERSION:S/.//:C/\..*//}.txt
.endif

.include <bsd.port.mk>
