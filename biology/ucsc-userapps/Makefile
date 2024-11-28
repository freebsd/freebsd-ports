PORTNAME=	ucsc-userapps
DISTVERSION=	474
CATEGORIES=	biology perl5 python
MASTER_SITES=	https://hgdownload.cse.ucsc.edu/admin/exe/userApps.archive/
DISTNAME=	userApps.v${DISTVERSION}.src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Command line tools from the UCSC Genome Browser project
WWW=		https://hgdownload.cse.ucsc.edu/admin/exe/

# Note: Some tools in the source dist are non-free for commercial use.
# If they are added to the install, the license below must be changed
# and packaging forbidden.
LICENSE=	MIT

BUILD_DEPENDS=	bash:shells/bash
# FIXME: Switch from mysql to mariadb
LIB_DEPENDS=	libmysqlclient.so:databases/mysql80-client \
		libunwind.so:devel/libunwind \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png
RUN_DEPENDS=	bash:shells/bash

USES=		gmake iconv localbase:ldflags shebangfix perl5 python:3.6+ ssl tar:tgz

SHEBANG_FILES=	kent/src/checkUmask.sh \
		kent/src/utils/bigHeat \
		kent/src/utils/chromToUcsc/chromToUcsc \
		kent/src/utils/tdbRename \
		kent/src/utils/tdbSort \
		kent/src/utils/trackDbIndexBb/trackDbIndexBb \
		kent/src/utils/ucscApiClient \
		kent/src/utils/webSync \
		kent/src/utils/bigGuessDb/bigGuessDb

WRKSRC=		${WRKDIR}/userApps
CFLAGS+=	-fcommon
MAKEFILE=	[Mm]akefile
MAKE_ENV=	BINDIR=${WRKSRC}/bin

SUB_FILES=	ucsc-shell

# Build mostly non-commercial tools.  There is some leakage of proprietary
# code from the libraries per conversation with UCSC.  Work to resolve this
# is ongoing.
do-build:
	@(test -f ${WRKSRC}/kent/src/inc/my_uuid.h || ${MV} ${WRKSRC}/kent/src/inc/uuid.h ${WRKSRC}/kent/src/inc/my_uuid.h)
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
