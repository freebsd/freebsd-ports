# New ports collection makefile for:	vegastrike-data
# Date created:		05 May 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	vegastrike
PORTVERSION=	0.5.0
CATEGORIES=	games
MASTER_SITES=	SF
PKGNAMESUFFIX=	-data
DISTNAME=	vegastrike-linux-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Vega Strike data files

USE_BZIP2=	yes
NO_BUILD=	yes

PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if defined(PACKAGE_BUILDING)
IGNORE=		ignore on pointyhat
.endif

post-patch:
	@${RM} -rf ${WRKSRC}/bin ${WRKSRC}/I* ${WRKSRC}/.vsinstall.sh.swp
	@${FIND} ${WRKSRC} -name "Makefile.am" -delete

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
		${FIND} . -type f -mindepth 1 | ${SORT} | \
			${SED} -e 's|^\./||; s|^|%%DATADIR%%/|' >> ${PLIST} && \
		${FIND} . -type d -mindepth 1 | ${SORT} -r | \
			${SED} -e 's|^\./||; s|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}

.include <bsd.port.mk>
