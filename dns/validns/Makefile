# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	validns
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	dns security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	umq@ueo.co.jp
COMMENT=	High performance DNS/DNSSEC zone validator

LICENSE=	BSD2CLAUSE

BROKEN_SSL=	openssl

LIB_DEPENDS=	libJudy.so:devel/judy

USES=		ssl

ALL_TARGET=

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	Changes README installation.mdwn notes.mdwn \
		technical-notes.mdwn todo.mdwn usage.mdwn

MAKE_ARGS+=	INCPATH=-I${LOCALBASE}/include
MAKE_ARGS+=	EXTRALPATH=-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	field has incomplete type 'EVP_MD_CTX' (aka 'struct evp_md_ctx_st')
BROKEN_FreeBSD_13=	field has incomplete type 'EVP_MD_CTX' (aka 'struct evp_md_ctx_st')
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
