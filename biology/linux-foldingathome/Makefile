# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	foldingathome
PORTVERSION=	5.04
CATEGORIES=	biology
MASTER_SITES=	http://www.stanford.edu/group/pandegroup/release/
PKGNAMEPREFIX=	linux-
DISTNAME=	FAH${PORTVERSION:S/.//}-Linux
EXTRACT_SUFX=	.exe

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed client for Protein Folding

USES=		linux
ONLY_FOR_ARCHS=	i386 amd64
REINPLACE_ARGS=
PLIST_FILES=	share/${PORTNAME}/${DISTNAME}${EXTRACT_SUFX} \
		bin/FoldingAtHome

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}
	${CHMOD} 755 ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${REINPLACE_CMD} -e "s|DATADIR|${DATADIR}|" ${SCRIPTDIR}/FoldingAtHome \
		| ${REINPLACE_CMD} -e "s|BINNAME|${DISTNAME}${EXTRACT_SUFX}|" \
		> ${STAGEDIR}${PREFIX}/bin/FoldingAtHome
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/FoldingAtHome
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
