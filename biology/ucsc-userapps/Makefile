PORTNAME=	ucsc-userapps
DISTVERSION=	414
PORTREVISION=	1
CATEGORIES=	biology perl5 python
MASTER_SITES=	http://hgdownload.cse.ucsc.edu/admin/exe/userApps.archive/
DISTNAME=	userApps.v${PORTVERSION}.src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line tools from the UCSC Genome Browser project
WWW=		https://hgdownload.cse.ucsc.edu/admin/exe/

LICENSE=	UCSC-GB
LICENSE_NAME=	UCSC Genome Browser License
LICENSE_TEXT=	Some tools installed by this port require a license for\
		commercial use.\n\nContact UCSC directly if you are using\
		these tools for commercial purposes.\n\nSee\
		https://genome.ucsc.edu/license/ for full terms.
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	uses _mm_popcnt_u64() function

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libpng.so:graphics/png
RUN_DEPENDS=	bash:shells/bash

USES=		gmake localbase:ldflags mysql shebangfix perl5 python ssl tar:tgz

RESTRICTED=	Redistribution is limited, see license

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

# Build mostly non-commercial tools.  There is some leakage of proprietary
# code from the libraries per conversation with UCSC.  Work to resolve this
# is ongoing.
do-build:
	@${MV} ${WRKSRC}/kent/src/inc/uuid.h ${WRKSRC}/kent/src/inc/my_uuid.h
	@${MKDIR} ${WRKSRC}/bin
	@(cd ${WRKSRC}/kent/src/lib && ${DO_MAKE_BUILD})
	@(cd ${WRKSRC}/kent/src/htslib && ${DO_MAKE_BUILD})
	@(cd ${WRKSRC}/kent/src/jkOwnLib && ${DO_MAKE_BUILD})
	@(cd ${WRKSRC}/kent/src/hg/lib && ${DO_MAKE_BUILD})
	@(cd ${WRKSRC}/kent/src/utils && ${DO_MAKE_BUILD})
	${CC} -DUCSC_PREFIX="\"${PREFIX}/userapps\"" ${FILESDIR}/kent.c -o ${WRKDIR}/kent

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
	${INSTALL_PROGRAM} ${WRKDIR}/kent ${STAGEDIR}${LOCALBASE}/bin

.include <bsd.port.mk>
