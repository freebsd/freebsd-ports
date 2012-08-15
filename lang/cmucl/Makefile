# Ports collection makefile for:    CMUCL
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#
#

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

LIB_DEPENDS=	c.6:${PORTSDIR}/misc/compat6x

# To make available on other archs, has to be cross-compiled (there is a
# script for this, but a configuration file has to be written).
IA32_BINARY_PORT=	yes
USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MAN1=		lisp.1 cmucl.1

PLIST_SUB=	VER=${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/lisp ${PREFIX}/bin
	cd ${WRKDIR} && ${FIND} lib | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}
	${INSTALL_MAN} ${WRKDIR}/man/man1/cmucl.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man/man1/lisp.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/cmucl/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
