# Ports collection makefile for:	gpc
# Date created:				January 27, 1999
# Whom:					Berend de Boer <berend@pobox.com>
#
# $FreeBSD$

PORTNAME=	gpc
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://agnes.dida.physik.uni-essen.de/gnu-pascal/beta/
DISTNAME=	gpc-19990118

MAINTAINER=	antonz@library.ntu-kpi.kiev.ua

BROKEN=		"Does not package correctly"

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/lang/gcc28:patch

WRKSRC=		${WRKDIR}/gpc
MAKE_ARGS=	LANGUAGES=pascal
USE_AUTOCONF=	yes
USE_GMAKE=	yes
ALL_TARGET=	bootstrap
INSTALL_TARGET=	pascal.install

MAN1=		gpc.1
MLINKS=		gpc.1 bpc.1 gpc.1 epc.1 gpc.1 pc.1

.include <bsd.port.pre.mk>

GNUHOST=	${ARCH}--freebsd${OSREL}

PLIST_SUB=	GNUHOST=${GNUHOST}
CONFIGURE_ARGS=	--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${GNUHOST}/2.8.1/include/g++

post-extract:
	@(${CP} -R ${WRKDIRPREFIX}${.CURDIR}/../../lang/gcc28/work/gcc-2.8.1/* ${WRKSRC})

pre-install:
	@${RM} -f ${WRKSRC}/p/doc/gpc.info*

post-install:
	install-info ${PREFIX}/info/gpc.info ${PREFIX}/info/dir

.include <bsd.port.post.mk>
