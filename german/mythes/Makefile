# $FreeBSD$

PORTNAME=	mythes
PORTVERSION=	2017.12.24
CATEGORIES=	german textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
DISTNAME=	Deutscher-Thesaurus-${PORTVERSION:C/\.//g}
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	German thesaurus

LICENSE=	LGPL21

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/th_de_DE_v2.idx \
		%%DATADIR%%/th_de_DE_v2.dat

DEALIASES=	de_AT de_BE de_CH de_LI de_LU

.for ALIAS in ${DEALIASES}
PLIST_FILES+=	%%DATADIR%%/th_${ALIAS}_v2.idx \
		%%DATADIR%%/th_${ALIAS}_v2.dat
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/th_de_DE_v2.dat ${WRKSRC}/th_de_DE_v2.idx ${STAGEDIR}${DATADIR}/
.for ALIAS in ${DEALIASES}
	${LN} -s th_de_DE_v2.dat ${STAGEDIR}${DATADIR}/th_${ALIAS}_v2.dat
	${LN} -s th_de_DE_v2.idx ${STAGEDIR}${DATADIR}/th_${ALIAS}_v2.idx
.endfor

.include <bsd.port.mk>
