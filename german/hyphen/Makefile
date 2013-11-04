# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2007.02.17
PORTREVISION=	1
CATEGORIES=	german textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
DISTNAME=	hyph_de_DE-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	German hyphenation rules

LICENSE=	LGPL21

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_de_DE.dic
PLIST_DIRSTRY=	%%DATADIR%%

DEALIASES=	de_AT de_BE de_CH de_LI de_LU
.for ALIAS in ${DEALIASES}
PLIST_FILES+=	%%DATADIR%%/hyph_${ALIAS}.dic
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_de_DE.dic ${STAGEDIR}${DATADIR}/
.for ALIAS in ${DEALIASES}
	${LN} -s hyph_de_DE.dic ${STAGEDIR}${DATADIR}/hyph_${ALIAS}.dic
.endfor

.include <bsd.port.mk>
