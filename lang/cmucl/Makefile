# Created by: cracauer@cons.org "Martin Cracauer"
# $FreeBSD$

PORTNAME=	cmucl
PORTVERSION=	19f
PORTREVISION=	2
CATEGORIES=	lang lisp
MASTER_SITES=	http://common-lisp.net/pub/project/cmucl/release/${PORTVERSION}/ \
		http://www.pmsf.de/pub/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.averillpark.net/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.linux.org.uk/pub/lisp/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.tepus.com/pub/project/cmucl/release/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-x86-freebsd_6.3-release

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The CMU implementation of Common Lisp

LIB_DEPENDS=	libc.so.6:misc/compat6x

# To make available on other archs, has to be cross-compiled (there is a
# script for this, but a configuration file has to be written).
IA32_BINARY_PORT=	yes
USES=		tar:bzip2
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_SUB=	VER=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lisp ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/man/man1/cmucl.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/lisp.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/cmucl/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
