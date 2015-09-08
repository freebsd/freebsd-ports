# Created by: Roman Bogorodskiy
# $FreeBSD$

PORTNAME=	phptags
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Create a tags file from PHP sources

LICENSE=	BSD2CLAUSE

DEPRECATED=	abandoned upstream
EXPIRATION_DATE=	2015-11-08

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/phptags etc/phptags.conf.sample man/man1/phptags.1.gz
PORTDOCS=	AUTHORS TODO README ChangeLog INSTALL

OPTIONS_DEFINE=	DOCS

post-install:
	@${INSTALL_DATA} ${WRKSRC}/phptags.conf.sample ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
