# Created by: ayu <ayunyan@gmail.com>
# $FreeBSD$

PORTNAME=	etqw
PORTVERSION=	2.0.r1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|etqw/|}
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-demo-server
DISTNAME=	ETQW-demo2-server-full.r1.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ayunyan@gmail.com
COMMENT=	Enemy Territory: QUAKE Wars Demo Server for Linux

NO_CDROM=	Redistribution is limited
NO_PACKAGE=	Package will be 428MB, set FORCE_PACKAGE if you really want it
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USES=		zip:infozip

ETQWDIR=	${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} -c +194885 ${_DISTDIR}${DISTNAME}.run > full.zip
	@(cd ${WRKSRC} && ${UNZIP_CMD} -q ${WRKSRC}/full.zip)
	@${RM} ${WRKSRC}/full.zip

post-patch:
	@${SED} -e 's|@ETQWDIR@|${ETQWDIR}|' ${FILESDIR}/etqwded-demo.in > ${WRKSRC}/etqwded-demo

do-install:
	@${MKDIR} ${ETQWDIR}

	${INSTALL_PROGRAM} ${WRKSRC}/etqwded-demo ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/data/etqwded.x86 ${ETQWDIR}
	@cd ${WRKSRC}/data && \
		${FIND} -E . -type f -iregex ".*\.so\.[0-9]+" \
			-exec ${INSTALL_DATA} "{}" "${ETQWDIR}/{}" \;

	@${MKDIR} ${ETQWDIR}/base/bots
	@cd ${WRKSRC}/data && \
		${FIND} base -type f \
			-exec ${INSTALL_DATA} "{}" "${ETQWDIR}/{}" \;

	@${MKDIR} ${ETQWDIR}/pb/htm
	@cd ${WRKSRC}/data && \
		${FIND} pb -type f \
			-exec ${INSTALL_DATA} "{}" "${ETQWDIR}/{}" \;

.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in EULA.txt README.txt copyrights.txt etqwtv.txt pb/PBEULA.txt
	@${INSTALL_DATA} ${WRKSRC}/data/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
