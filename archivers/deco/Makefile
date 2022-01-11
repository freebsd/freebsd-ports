PORTNAME=	deco
PORTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	archivers
PKGNAMESUFFIX=	-extractor # avoid collision with misc/deco

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to extract various archive file formats

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	peha
GH_PROJECT=	deco-archive:archive
GH_TAGNAME=	${DARCHIVE_VER}:archive

RUN_DEPENDS=	arc:archivers/arc \
		arj:archivers/arj \
		cabextract:archivers/cabextract \
		dpkg:archivers/dpkg \
		lzop:archivers/lzop \
		7zz:archivers/7-zip \
		rpm:archivers/rpm4 \
		rzip:archivers/rzip \
		unace:archivers/unace \
		unrar:archivers/unrar \
		zoo:archivers/zoo \
		flac:audio/flac

DARCHIVE_VER=	1.7
DARCHIVE=	deco-archive-${DARCHIVE_VER}

post-patch:
	@${CP} ${FILESDIR}/extract ${WRKDIR}/${DARCHIVE}/x/"tar\.xz"
	${REINPLACE_CMD} 's/7za/7zz/;s,-l ,,' ${WRKDIR}/${DARCHIVE}/x/7z/extract

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deco ${STAGEDIR}${PREFIX}/bin/deco-extract
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in LICENSE Makefile NEWS README config.mk
	${RM} -r ${WRKSRC}/../${DARCHIVE}/${i}
.endfor
	@cd ${WRKDIR}/${DARCHIVE}/x/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${FIND} ${STAGEDIR}${DATADIR} -type f -exec ${CHMOD} +x {} \;

.include <bsd.port.mk>
