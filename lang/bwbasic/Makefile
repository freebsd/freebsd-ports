# Created by: msmith@gsoft.com.au
# $FreeBSD$

PORTNAME=	bwbasic
PORTVERSION=	3.20
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/version%20${PORTVERSION}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Bywater Basic interpreter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

NO_WRKSUBDIR=	yes

USES=		dos2unix zip
GNU_CONFIGURE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS} -Wall -ansi"

PORTDOCS=	*

PLIST_FILES=	bin/${PORTNAME} \
		bin/renum

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${CHMOD} a+x ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.doc ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
