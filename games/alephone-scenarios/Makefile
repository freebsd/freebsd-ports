# New ports collection makefile for:	alephone-scenarios
# Date created:				2007-03-06
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	scenarios
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://trilogyrelease.bungie.org/files/:bungie \
		http://files5.bungie.org/marathon/:rubicon \
		http://nardofiles.bungie.org/:nardofiles \
		http://eternal.bungie.org/files/_releases/:eternal \
		SF/emr3:emr
PKGNAMEPREFIX=	alephone-
DISTFILES=	#
DIST_SUBDIR=	alephone
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free scenarios for the Aleph One engine

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	EMR "Install Excalibur: Morgana's Revenge data" off \
		ETERNAL "Install Eternal data" off \
		EVIL "Install Marathon Evil data" on \
		RED "Install Marathon Red data" on \
		RUBICON "Install Rubicon X data" off \
		TI "Install Tempus Irae data" off

SUB_FILES=	wrapper

.include <bsd.port.pre.mk>

DATADIR!=	cd ${PORTSDIR}/games/alephone && ${MAKE} -V DATADIR

.if defined(WITH_EMR)
EMR_FILE=	emr-20070121.tar.gz
DISTFILES+=	${EMR_FILE}:emr
PLIST_SUB+=	EMR=""
AO_PACKS+=	emr
.else
PLIST_SUB+=	EMR="@comment "
.endif

.if defined(WITH_ETERNAL)
DISTFILES+=	Eternal5SDL512${EXTRACT_SUFX}:eternal
EXTRACT_ONLY+=	Eternal5SDL512${EXTRACT_SUFX}
PLIST_SUB+=	ETERNAL=""
AO_PACKS+=	eternal
.else
PLIST_SUB+=	ETERNAL="@comment "
.endif

.if !defined(WITHOUT_EVIL)
DISTFILES+=	MarathonEvil${EXTRACT_SUFX}:bungie
EXTRACT_ONLY+=	MarathonEvil${EXTRACT_SUFX}
PLIST_SUB+=	EVIL=""
AO_PACKS+=	evil
.else
PLIST_SUB+=	EVIL="@comment "
.endif

.if !defined(WITHOUT_RED)
DISTFILES+=	MarathonRED${EXTRACT_SUFX}:bungie
EXTRACT_ONLY+=	MarathonRED${EXTRACT_SUFX}
PLIST_SUB+=	RED=""
AO_PACKS+=	red
.else
PLIST_SUB+=	RED="@comment "
.endif

.if defined(WITH_RUBICON)
DISTFILES+=	marathonRubiconX${EXTRACT_SUFX}:rubicon
EXTRACT_ONLY+=	marathonRubiconX${EXTRACT_SUFX}
PLIST_SUB+=	RUBICON=""
AO_PACKS+=	rubicon
.else
PLIST_SUB+=	RUBICON="@comment "
.endif

.if defined(WITH_TI)
DISTFILES+=	Tempus_Irae${EXTRACT_SUFX}:nardofiles
EXTRACT_ONLY+=	Tempus_Irae${EXTRACT_SUFX}
PLIST_SUB+=	TI=""
AO_PACKS+=	tempus_irae
.else
PLIST_SUB+=	TI="@comment "
.endif

.if empty(AO_PACKS)
IGNORE=		needs at least one option
.endif

post-extract:
.if defined(WITH_EMR)
	@${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/${EMR_FILE} -C ${WRKDIR}
	@${MKDIR} ${WRKSRC}/emr
	@cd ${WRKSRC}/${EMR_FILE:S/.tar.gz//} && \
		${MV} share-emr/* ../emr && \
		${MV} share-doc-emr ../emr/docs && \
		${MV} README ../emr/docs
.endif
.if defined(WITH_ETERNAL)
	@cd ${WRKSRC} && ${MV} "Eternal Mk V SDL 512" eternal
	@cd ${WRKSRC}/eternal && ${RM} *.exe *.dll
.endif
.if !defined(WITHOUT_EVIL)
	@cd ${WRKSRC} && ${MV} "Marathon EVIL" evil
.endif
.if !defined(WITHOUT_RED)
	@cd ${WRKSRC} && ${MV} "Marathon RED" red
.endif
.if defined(WITH_RUBICON)
	@cd ${WRKSRC} && ${MV} "Rubicon X "?? rubicon
.endif
.if defined(WITH_TI)
	@cd ${WRKSRC} && ${MV} Tempus_Irae tempus_irae
	@cd ${WRKSRC}/tempus_irae && \
		${FIND} . -type d -print0 | ${XARGS} -0 ${CHMOD} 755 && \
		${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} 644
.endif

pre-install:
.for f in ${AO_PACKS}
	@cd ${WRKSRC} && ${SED} -e 's|%%GAMEDIR%%|${f}|' wrapper > alephone-${f}
.endfor

do-install:
.for f in ${AO_PACKS}
	${INSTALL_SCRIPT} ${WRKDIR}/alephone-${f} ${PREFIX}/bin
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
	@cd ${DATADIR}/${f} && \
		${FIND} . -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE} && \
		${FIND} . -type f -print0 | ${XARGS} -0 ${CHMOD} ${SHAREMODE}
.endfor
.if defined(WITH_RUBICON)
	@${LN} -s ${DATADIR}/[A-Z]* ${DATADIR}/rubicon
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
