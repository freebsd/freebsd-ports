# Created by: Murray Stokely <murray@cdrom.com>

PORTNAME=	nasm
PORTVERSION=	2.15.05
PORTEPOCH=	1
CATEGORIES=	devel lang
MASTER_SITES=	https://www.nasm.us/pub/nasm/releasebuilds/${PORTVERSION}/ \
		https://mirror.sobukus.de/files/src/nasm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General-purpose multi-platform x86 and amd64 assembler

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_strspn=yes
USES=		compiler:c11 cpe tar:xz gmake perl5
USE_PERL5=	build
MAKE_ARGS+=	INSTALLROOT=${STAGEDIR}
INSTALL_TARGET=	install #needed for RDOFF_INSTALL_TARGET
CPE_VENDOR=	nasm
CPE_PRODUCT=	netwide_assembler

OPTIONS_DEFINE=	RDOFF DOCS
OPTIONS_SUB=	yes

RDOFF_DESC=		Install tools to handle RDOFF object files
RDOFF_INSTALL_TARGET=	install_rdf

DOCS_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-xdoc${EXTRACT_SUFX}
PORTDOCS=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/nasmdoc.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
