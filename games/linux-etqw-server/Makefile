# New ports collection makefile for:	etqw-server
# Date created:		2008-04-21
# Whom:			Ayumi M <ayu@commun.jp>
#
# $FreeBSD$
#

PORTNAME=	etqw
PORTVERSION=	1.4.r1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE:S|$|etqw/|}
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-server
DISTNAME=	ETQW${PKGNAMESUFFIX}-1.4-full.x86
DISTFILES=	ETQW${PKGNAMESUFFIX}-1.4-full.x86.run ETQW${PKGNAMESUFFIX}-1.4-hotfix.r1.zip

MAINTAINER=	ayu@commun.jp
COMMENT=	Enemy Territory: QUAKE Wars Server for Linux

NO_CDROM=	Redistribution is limited
NO_PACKAGE=	Package will be 428MB, set FORCE_PACKAGE if you really want it
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_ZIP=	yes

ETQWDIR=	${PREFIX}/lib/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && \
		${TAIL} -c +194885 ${_DISTDIR}ETQW${PKGNAMESUFFIX}-1.4-full.x86.run > full.zip
	@(cd ${WRKSRC} && ${UNZIP_CMD} -q ${WRKSRC}/full.zip)
	@${RM} ${WRKSRC}/full.zip
	@cd ${WRKSRC} && \
		${UNZIP_CMD} -q ${_DISTDIR}ETQW${PKGNAMESUFFIX}-1.4-hotfix.r1.zip

post-patch:
	@${MV} ${WRKSRC}/etqwded.x86 ${WRKSRC}/data

	@${SED} -e 's|@ETQWDIR@|${ETQWDIR}|' ${FILESDIR}/etqwded.in > ${WRKSRC}/etqwded

do-install:
	@${MKDIR} ${ETQWDIR}

	${INSTALL_PROGRAM} ${WRKSRC}/etqwded ${PREFIX}/bin
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
