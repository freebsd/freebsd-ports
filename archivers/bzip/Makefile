# New ports collection makefile for:    bzip
# Date created:         Fr  27 Sep 1996 11:47:35 MET DST
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	bzip
PORTVERSION=	0.21
CATEGORIES=	archivers
MASTER_SITES=	http://custom.lab.unb.br/pub/compression/bzip/ \
		http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A block-sorting file compressor

DEPRECATED=	see full description
RESTRICTED=	may be covered by patents
MAN1=		bzip.1 bunzip.1

PLIST_FILES=	bin/bzip bin/bunzip

pre-install:
	@${CAT} ${FILESDIR}/COPYRIGHT

do-install:
	${RM} -f ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_PROGRAM} ${WRKSRC}/bzip ${PREFIX}/bin/bzip
	${LN} -fs ${PREFIX}/bin/bzip ${PREFIX}/bin/bunzip
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${MAN1PREFIX}/man/man1/bzip.1
	${INSTALL_MAN} ${WRKSRC}/bzip.1 ${MAN1PREFIX}/man/man1/bunzip.1

.include <bsd.port.mk>
