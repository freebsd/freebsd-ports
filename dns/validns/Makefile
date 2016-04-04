# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	validns
PORTVERSION=	0.8
CATEGORIES=	dns security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	umq@ueo.co.jp
COMMENT=	High performance DNS/DNSSEC zone validator

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libJudy.so:devel/judy

USE_OPENSSL=	yes
WITH_OPENSSL_PORT=yes

ALL_TARGET=

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	Changes README installation.mdwn notes.mdwn \
		technical-notes.mdwn todo.mdwn usage.mdwn

MAKE_ARGS+=	INCPATH=-I${LOCALBASE}/include
MAKE_ARGS+=	EXTRALPATH=-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
