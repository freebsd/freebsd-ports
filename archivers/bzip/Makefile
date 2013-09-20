# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	bzip
PORTVERSION=	0.21
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.42.org/pub/OLD/b/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Block-sorting file compressor

NO_STAGE=	yes
RESTRICTED=	may be covered by patents
MAN1=		bzip.1 bunzip.1
USE_CSTD=	gnu89

PLIST_FILES=	bin/bzip bin/bunzip

pre-install:
	@${CAT} ${FILESDIR}/COPYRIGHT

do-install:
	${RM} -f ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_PROGRAM} ${WRKSRC}/bzip ${PREFIX}/bin
	${LN} -fs bzip ${PREFIX}/bin/bunzip
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${MAN1PREFIX}/man/man1/bzip.1
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${MAN1PREFIX}/man/man1/bunzip.1

.include <bsd.port.mk>
