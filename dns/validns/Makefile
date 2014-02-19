# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	validns
PORTVERSION=	0.7
CATEGORIES=	dns security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	umq@ueo.co.jp
COMMENT=	High performance DNS/DNSSEC zone validator

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libJudy.so:${PORTSDIR}/devel/judy

ALL_TARGET=

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
OPTIONS_DEFINE=	DOCS
PORTDOCS=	Changes README installation.mdwn notes.mdwn \
		technical-notes.mdwn todo.mdwn usage.mdwn

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
