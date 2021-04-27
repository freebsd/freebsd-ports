# Created by: J. Bacon <jwb@FreeBSD.org>

PORTNAME=	ucsc-userapps
DISTVERSION=	413
CATEGORIES=	biology perl5 python
MASTER_SITES=	http://hgdownload.cse.ucsc.edu/admin/exe/userApps.archive/
DISTNAME=	userApps.v${PORTVERSION}.src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line tools from the UCSC Genome Browser project

LICENSE=	UCSC-GB
LICENSE_NAME=	UCSC Genome Browser License
LICENSE_TEXT=	To the best of our knowledge, all of the tools installed by\
		this port are freely available.  However, a license is\
		required for commercial download and installation of some\
		binaries and source code in the UCSC Genome Browser\
		distribution.\n\nContact UCSC directly if you are using these\
		tools for commercial purposes.\n\nSee\
		https://genome.ucsc.edu/license/ for full terms.
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	_mm_popcnt_u64

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libmysqlclient.so:databases/mysql57-client \
		libpng.so:graphics/png
RUN_DEPENDS=	bash:shells/bash

USES=		gmake localbase:ldflags shebangfix perl5 python:3.6+ ssl tar:tgz

SHEBANG_FILES=	kent/src/checkUmask.sh \
		kent/src/utils/bigHeat \
		kent/src/utils/chromToUcsc/chromToUcsc \
		kent/src/utils/tdbRename \
		kent/src/utils/tdbSort \
		kent/src/utils/trackDbIndexBb/trackDbIndexBb \
		kent/src/utils/ucscApiClient \
		kent/src/utils/webSync

WRKSRC=		${WRKDIR}/userApps
CFLAGS+=	-fcommon
MAKEFILE=	[Mm]akefile
MAKE_ENV=	BINDIR=${WRKSRC}/bin

SUB_FILES=	ucsc-shell

# Build only non-commercial tools
do-build:
	@${MV} ${WRKSRC}/kent/src/inc/uuid.h ${WRKSRC}/kent/src/inc/my_uuid.h
	@${MKDIR} ${WRKSRC}/bin
	@(cd ${WRKSRC}/kent/src/lib && ${DO_MAKE_BUILD})
	@(cd ${WRKSRC}/kent/src/htslib && ${DO_MAKE_BUILD})
	@(cd ${WRKSRC}/kent/src/jkOwnLib && ${DO_MAKE_BUILD})
	@(cd ${WRKSRC}/kent/src/hg/lib && ${DO_MAKE_BUILD})
	@(cd ${WRKSRC}/kent/src/utils && ${DO_MAKE_BUILD})

do-install:
	@${MKDIR} ${WRKSRC}/scripts ${WRKSRC}/binaries
	@${CP} $$(file ${WRKSRC}/bin/* | fgrep ELF | cut -d : -f 1) \
		${WRKSRC}/binaries
	@${CP} $$(file ${WRKSRC}/bin/* | fgrep -v ELF | cut -d : -f 1) \
		${WRKSRC}/scripts
	@${MKDIR} ${STAGEDIR}${PREFIX}/userapps/bin
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/* \
		${STAGEDIR}${PREFIX}/userapps/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* \
		${STAGEDIR}${PREFIX}/userapps/bin
	${INSTALL_SCRIPT} ${WRKDIR}/ucsc-shell \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
