# Created by: Scott Flatman <sf@dsinw.com>
# $FreeBSD$

PORTNAME=	cmucl-extra
PORTVERSION=	19c
PORTREVISION=	1
CATEGORIES=	lang lisp
MASTER_SITES=	ftp://ftp.common-lisp.net/pub/project/cmucl/release/${PORTVERSION}/ \
		http://www.pmsf.de/pub/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.averillpark.net/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.linux.org.uk/pub/lisp/cmucl/release/${PORTVERSION}/ \
		ftp://ftp.tepus.com/pub/project/cmucl/release/${PORTVERSION}/
DISTNAME=	cmucl-${PORTVERSION}-x86-FreeBSD.extra

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optional extras for the CMU implementation of Common Lisp

BUILD_DEPENDS=	lisp:lang/cmucl
RUN_DEPENDS=	lisp:lang/cmucl

USES=		tar:bzip2
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX})
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/cmucl/lib/motifd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/cmucl/lib/motifd
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/lib/cmucl/lib/motifd

.include <bsd.port.mk>
