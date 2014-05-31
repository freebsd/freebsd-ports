# Created by: Scott Flatman <sf@dsinw.com>
# $FreeBSD$

PORTNAME=	cmucl-extra
PORTVERSION=	19c
CATEGORIES=	lang lisp
MASTER_SITES=	ftp://ftp.common-lisp.net/pub/project/cmucl/release/${PORTVERSION}/ \
		http://www.pmsf.de/pub/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.averillpark.net/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.linux.org.uk/pub/lisp/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.tepus.com/pub/project/cmucl/release/${PORTVERSION}/
DISTNAME=	cmucl-${PORTVERSION}-x86-FreeBSD.extra

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optional extras for the CMU implementation of Common Lisp

BUILD_DEPENDS=	lisp:${PORTSDIR}/lang/cmucl
RUN_DEPENDS=	lisp:${PORTSDIR}/lang/cmucl

USES=		tar:bzip2
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKDIR} && ${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX})

.include <bsd.port.mk>
