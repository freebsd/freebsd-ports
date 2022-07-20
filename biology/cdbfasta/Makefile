PORTNAME=	cdbfasta
PORTVERSION=	2010.07.22
CATEGORIES=	biology
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Fast indexing and retrieval of FASTA records from flat file databases

# LICENSE=	unspecified

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake

PLIST_FILES=	bin/cdbfasta bin/cdbyank

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdbfasta ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/cdbyank ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
