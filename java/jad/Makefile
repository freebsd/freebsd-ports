PORTNAME=	jad
PORTVERSION=	1.5.8c
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	https://varaneckas.com/jad/
DISTNAME=	jad158c.freebsd

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java Decompiler

DEPRECATED=	This is a version that is over 25 years old and has multiple vulnerabilities
EXPIRATION_DATE=2026-06-30

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/jad

PORTDOCS=	*

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jad ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
