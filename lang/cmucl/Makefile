# Created by: cracauer@cons.org "Martin Cracauer"
# $FreeBSD$

PORTNAME=	cmucl
DISTVERSION=	21b
CATEGORIES=	lang lisp
MASTER_SITES=	https://common-lisp.net/project/cmucl/downloads/release/${DISTVERSION}/ \
		http://cmucl.org/downloads/release/${DISTVERSION}/ \
		https://pmsf.eu/pub/cmucl/release/${DISTVERSION}/ \
		http://www.rgrjr.com/cmucl/downloads/release/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-x86-FreeBSD

MAINTAINER=	phascolarctos@protonmail.ch
COMMENT=	CMU implementation of Common Lisp

LICENSE=	PD

USES=		tar:bzip2

# To make available on other archs, has to be cross-compiled (there is a
# script for this, but a configuration file has to be written).
IA32_BINARY_PORT=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_SUB=	VER=${DISTVERSION}

OPTIONS_DEFINE=	DOCS

INFO=	asdf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lisp ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/man1/cmucl.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/lisp.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MV} ${STAGEDIR}${PREFIX}/lib/cmucl/lib/contrib/asdf/doc/asdf.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/cmucl/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
