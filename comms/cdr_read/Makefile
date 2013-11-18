# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	cdr_read
PORTVERSION=	1.09
CATEGORIES=	comms
MASTER_SITES=	http://www.gamma.ru/~avk/
DISTNAME=	cdrr${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for reading of the call detail records from PBX

USES=		dos2unix
DOS2UNIX_FILES=	readme_eng.txt
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme_eng.txt ${STAGEDIR}${DOCSDIR}/readme.txt

.include <bsd.port.mk>
