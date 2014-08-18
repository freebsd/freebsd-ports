# Created by: msmith@gsoft.com.au
# $FreeBSD$

PORTNAME=	bwbasic
PORTVERSION=	2.61
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/version%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Bywater Basic interpreter

NO_WRKSUBDIR=	yes

USES=		dos2unix zip
GNU_CONFIGURE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS} -ansi"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${CHMOD} a+x ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} 's|bindir)|DESTDIR)$$(&|' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.doc ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/bwbtest; ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
