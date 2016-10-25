# $FreeBSD$

PORTNAME=	deco
PORTVERSION=	1.6.4
CATEGORIES=	archivers

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Program to extract various archive file formats

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	peha
GH_PROJECT=	deco-archive:archive
GH_TAGNAME=	1.7:archive

RUN_DEPENDS=	arc:archivers/arc \
		arj:archivers/arj \
		cabextract:archivers/cabextract \
		dpkg:archivers/dpkg \
		lzop:archivers/lzop \
		7z:archivers/p7zip \
		rpm:archivers/rpm4 \
		rzip:archivers/rzip \
		unace:archivers/unace \
		unrar:archivers/unrar \
		zoo:archivers/zoo \
		flac:audio/flac

CONFLICTS=	deco-[0-9]*

post-patch:
	@${CP} ${FILESDIR}/extract ${WRKDIR}/${PORTNAME}-archive-1.7/x/"tar\.xz"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/deco ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in LICENSE Makefile NEWS README config.mk
	${RM} -r ${WRKSRC}/../${PORTNAME}-archive-1.7/${i}
.endfor
	@cd ${WRKDIR}/${PORTNAME}-archive-1.7/x/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@${FIND} ${STAGEDIR}${DATADIR} -type f -exec ${CHMOD} +x {} \;

.include <bsd.port.mk>
