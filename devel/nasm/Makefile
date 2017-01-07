# Created by: Murray Stokely <murray@cdrom.com>
# $FreeBSD$

PORTNAME=	nasm
PORTVERSION=	2.11.08
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://www.nasm.us/pub/nasm/releasebuilds/${PORTVERSION}/

MAINTAINER=	serio.jeffrey@gmail.com
COMMENT=	General-purpose multi-platform x86 and amd64 assembler

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_strspn=yes
USES=		tar:xz gmake
MAKE_ARGS+=	INSTALLROOT=${STAGEDIR}
INSTALL_TARGET=	install #needed for RDOFF_INSTALL_TARGET

OPTIONS_DEFINE=	RDOFF DOCS
OPTIONS_DEFAULT=RDOFF
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
