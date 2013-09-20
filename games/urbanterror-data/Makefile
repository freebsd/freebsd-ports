# Created by: alepulver
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	4.2.014
CATEGORIES=	games
MASTER_SITES=	http://cdn.urbanterror.info/urt/42/zips/ \
		http://www.f1m.fr/uploads/urt/ \
		http://mirror.urtstats.net/urbanterror/
PKGNAMEPREFIX=	urbanterror-
DISTNAME=	UrbanTerror${URT_VER}_full${URT_REV}
EXTRACT_SUFX=	.zip
EXTRACT_ONLY=

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Standalone realism based mod originally for Quake III Arena

NO_BUILD=	yes
NO_PACKAGE=	Package will be 1GB; set FORCE_PACKAGE if you really want it

DATADIR=	${PREFIX}/share/quake3
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

URT_VER=	${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
URT_REV=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.([0-9]+)/\2/}

PLIST_SUB+=	VER=${URT_VER}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${DATADIR}/q3ut4
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTFILES} \
		${EXTRACT_AFTER_ARGS} -C ${DATADIR} --strip-components 1 \
		UrbanTerror${URT_VER}/q3ut4
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${MV} ${DATADIR}/q3ut4/readme${URT_VER}.txt ${DOCSDIR}
.else
	${RM} ${DATADIR}/q3ut4/readme${URT_VER}.txt
.endif

.include <bsd.port.mk>
