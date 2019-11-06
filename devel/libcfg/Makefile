# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcfg
PORTVERSION=	0.6.2
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://opensource.platon.org/projects/
DISTNAME=	${PORTNAME}+-${DISTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library for command line and configuration file parsing

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to link: relocation R_AARCH64_ADR_PREL_PG_HI21 against symbol cfg_default_properties cannot be used when making a shared object

CONFLICTS_INSTALL=	ossp-cfg

USES=		autoreconf gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes

INSTALL_TARGET=	install-strip install-man

PORTDOCS=	*

OPTIONS_DEFINE=	EXAMPLES DOCS
OPTIONS_SUB=	yes

CFLAGS_amd64=	-fPIC

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
