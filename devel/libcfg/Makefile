# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcfg
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://opensource.platon.org/projects/
DISTNAME=	${PORTNAME}+-${DISTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library for command line and configuration file parsing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip install-man

PORTDOCS=	*

OPTIONS_DEFINE=	EXAMPLES DOCS
OPTIONS_SUB=	yes

CFLAGS_amd64=	-fPIC
CFLAGS_ia64=	-fPIC

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/example.* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for FILE in AUTHORS README TODO
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	for FILE in ${WRKSRC}/doc/html/*; do \
		${INSTALL_DATA} $${FILE} ${STAGEDIR}${DOCSDIR}/html; \
	done

.include <bsd.port.mk>
