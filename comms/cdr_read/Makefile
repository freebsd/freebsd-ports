# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	cdr_read
PORTVERSION=	1.09
CATEGORIES=	comms
MASTER_SITES=	http://www.gamma.ru/~avk/
DISTNAME=	cdrr${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for reading of the call detail records from PBX

BROKEN=		unfetchable

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_TEXT=	This program can be freely distributed and used for\
		any legal purposes if the information about my authorship\
		is preserved.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		dos2unix
DOS2UNIX_FILES=	readme_eng.txt
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme_eng.txt ${STAGEDIR}${DOCSDIR}/readme.txt

.include <bsd.port.mk>
