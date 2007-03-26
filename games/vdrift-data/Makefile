# New ports collection makefile for:	vdrift-data
# Date created:		2006-02-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	20070323
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vdrift
PKGNAMEPREFIX=	vdrift-
DISTFILES=	#
DIST_SUBDIR=	vdrift

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Vdrift driving simulation data files

USE_BZIP2=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/vdrift
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}2007-03-23-src

OPTIONS=	MINIMAL	"Install minimal requerimients of data files" off \
		FULL	"Install all data files"	on

.include <bsd.port.pre.mk>

.if defined(WITH_FULL) && defined(WITH_MINIMAL)
pre-everything::
	@${ECHO_CMD} "##############################################################"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " * Please only select one option, try \"make config\" again"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "##############################################################"
	@${FALSE}
.endif

.if defined(WITH_MINIMAL)
DISTFILES+=	${PKGNAMEPREFIX}2007-03-23-${PORTNAME}-minimal.tar.bz2
.endif

.if defined(WITH_FULL)
DISTFILES+=	${PKGNAMEPREFIX}2007-03-23-${PORTNAME}-full.tar.bz2
.endif

post-extract:
	@cd ${WRKSRC}/data && \
		${FIND} * -name SConscript -print0 | ${XARGS} -0 ${RM}
.for DIRE in settings/replays settings/screenshots carparts/turbo carparts/transmission \
		carparts/suspension carparts/other carparts/exhaust carparts/engine
	@${RMDIR} ${WRKSRC}/data/${DIRE}
.endfor

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}/data && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.post.mk>
