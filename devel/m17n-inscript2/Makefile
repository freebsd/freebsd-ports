PORTNAME=	inscript2
PORTVERSION=	20210820
CATEGORIES=	devel textproc
MASTER_SITES=	https://releases.pagure.org/${PORTNAME}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Enhanced Inscript keyboard layouts for Indic languages
WWW=		https://pagure.io/inscript2

LICENSE=	LGPL21

BUILD_DEPENDS=	m17n-db:devel/m17n-db
RUN_DEPENDS=	m17n-db:devel/m17n-db

DEPRECATED=	Included in m17n-db-1.8.10 (to be committed)
EXPIRATION_DATE=2025-06-30	# Or before once devel/m17n-db is upgraded

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
M17N_DATADIR=	${PREFIX}/share/m17n

do-build:
	${REINPLACE_CMD} -e 's|/usr/share/m17n|${STAGEDIR}${M17N_DATADIR}|'	\
		${WRKSRC}/${MAKEFILE}
	${MKDIR} ${STAGEDIR}${M17N_DATADIR}/icons

.include <bsd.port.mk>
