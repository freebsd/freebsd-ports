# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	bam
PORTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	http://github.com/downloads/matricks/bam/

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	A fast and flexible build system using Lua

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

USE_BZIP2=	yes

PLIST_FILES=	bin/bam

NO_STAGE=	yes
do-build:
.if defined(CC) && ${CC:T:Mclang}
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/make_unix_clang.sh
	(cd ${WRKSRC} && ${SH} make_unix_clang.sh)
.else
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/make_unix.sh
	(cd ${WRKSRC} && ${SH} make_unix.sh)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bam ${PREFIX}/bin

.include <bsd.port.mk>
