# New ports collection makefile for:	netbsd-pkgsrc-mk-files
# Date created:				16 September 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	netbsd-pkgsrc-mk-files
PORTVERSION=	20090329
CATEGORIES=	devel
MASTER_SITES=	http://www.mova.org/~cheusov/pub/netbsd-tools/pkgsrc-mk-files/ \
		http://trociny.googlecode.com/files/

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Collection of mk-files from pkgsrc project

RUN_DEPENDS=	bmake:${PORTSDIR}/devel/bmake

USE_BZIP2=	YES
DATADIR=	${PREFIX}/share/mk
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && \
	MK_DST=${DATADIR} OPSYS=FreeBSD SYSCONFDIR=${PREFIX}/etc \
	ROOT_GROUP=wheel ROOT_USER=root \
	CP=cp SED=sed \
	${SH} bootstrap.sh

.include <bsd.port.mk>
