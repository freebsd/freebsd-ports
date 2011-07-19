# New ports collection makefile for:	alephone-data
# Date created:		08 March 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.mariusnet.com/files/Marathon/
PKGNAMEPREFIX=	alephone-
DISTFILES=	#
DIST_SUBDIR=	alephone

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Released Marathon data files for the Aleph One port

RUN_DEPENDS=	alephone:${PORTSDIR}/games/alephone

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_CDROM=	Bungie/Microsoft do not allow charging for Marathon data files

OPTIONS=	MARATHON "Install Marathon data" on \
		DURANDAL "Install Marathon 2: Durandal data" on \
		INFINITY "Install Marathon Infinity data" on

SUB_FILES=	wrapper

.include <bsd.port.pre.mk>

DATADIR!=	cd ${PORTSDIR}/games/alephone && ${MAKE} -V DATADIR

.if !defined(WITHOUT_MARATHON)
DISTFILES+=	M1A1${EXTRACT_SUFX}
PLIST_SUB+=	MARATHON=""
AO_PACKS+=	marathon
.else
PLIST_SUB+=	MARATHON="@comment "
.endif

.if !defined(WITHOUT_DURANDAL)
DISTFILES+=	Marathon2${EXTRACT_SUFX}
PLIST_SUB+=	DURANDAL=""
AO_PACKS+=	durandal
.else
PLIST_SUB+=	DURANDAL="@comment "
.endif

.if !defined(WITHOUT_INFINITY)
DISTFILES+=	MarathonInfinity${EXTRACT_SUFX}
PLIST_SUB+=	INFINITY=""
AO_PACKS+=	infinity
.else
PLIST_SUB+=	INFINITY="@comment "
.endif

.if empty(AO_PACKS)
IGNORE=		needs at least one game option (MARATHON, DURANDAL and INFINITY)
.endif

post-extract:
.if !defined(WITHOUT_MARATHON)
	@cd ${WRKSRC} && ${MV} M1A1 marathon
.endif
.if !defined(WITHOUT_DURANDAL)
	@cd ${WRKSRC} && ${MV} "Marathon 2" durandal
.endif
.if !defined(WITHOUT_INFINITY)
	@cd ${WRKSRC} && ${MV} "Marathon Infinity" infinity
.endif

pre-install:
.for f in ${AO_PACKS}
	@cd ${WRKSRC} && ${SED} -e 's|%%GAMEDIR%%|${f}|' wrapper > alephone-${f}
.endfor

do-install:
.for f in ${AO_PACKS}
	${INSTALL_SCRIPT} ${WRKSRC}/alephone-${f} ${PREFIX}/bin
	${CP} -R ${WRKSRC}/${f} ${DATADIR}
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
