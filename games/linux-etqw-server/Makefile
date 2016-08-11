# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	etqw
PORTVERSION=	1.5
CATEGORIES=	games linux
MASTER_SITES=	http://ftp.4players.de/pub/hosted/wolfenstein/users/etqw/server/ \
		ftp://ftp0.uk.multiplay.co.uk/pub/games/fps/enemyterritory_quakewars/server/linux/ \
		ftp://ftp0.nl.multiplay.co.uk/pub/games/fps/enemyterritory_quakewars/server/linux/ \
		IDSOFTWARE/etqw
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-server
DISTNAME=	ETQW${PKGNAMESUFFIX}-1.5-full.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enemy Territory: QUAKE Wars Server for Linux

NO_CDROM=	Redistribution is limited
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USES=		zip:infozip

ETQWDIR=	${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
OPTIONS_DEFINE=	DOCS

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} -c +194885 ${_DISTDIR}ETQW${PKGNAMESUFFIX}-1.5-full.x86.run > full.zip
	@(cd ${WRKSRC} && ${UNZIP_CMD} -q ${WRKSRC}/full.zip)
	@${RM} ${WRKSRC}/full.zip

post-patch:
	@${SED} -e 's|@ETQWDIR@|${ETQWDIR}|' ${FILESDIR}/etqwded.in > ${WRKSRC}/etqwded

do-install:
	@${MKDIR} ${STAGEDIR}${ETQWDIR}

	${INSTALL_PROGRAM} ${WRKSRC}/etqwded ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/data/etqwded.x86 ${STAGEDIR}${ETQWDIR}
	@cd ${WRKSRC}/data && \
		${FIND} -E . -type f -iregex ".*\.so\.[0-9]+" \
			-exec ${INSTALL_DATA} "{}" "${STAGEDIR}${ETQWDIR}/{}" \;

	@${MKDIR} ${STAGEDIR}${ETQWDIR}/base/bots
	@cd ${WRKSRC}/data && \
		${FIND} base -type f \
			-exec ${INSTALL_DATA} "{}" "${STAGEDIR}${ETQWDIR}/{}" \;

	@${MKDIR} ${STAGEDIR}${ETQWDIR}/pb/htm
	@cd ${WRKSRC}/data && \
		${FIND} pb -type f \
			-exec ${INSTALL_DATA} "{}" "${STAGEDIR}${ETQWDIR}/{}" \;

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in EULA.txt README.txt copyrights.txt etqwtv.txt readme_1_5_patch.txt server_readme.txt pb/PBEULA.txt
	@${INSTALL_DATA} ${WRKSRC}/data/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
