# Created by: Mikolaj Golub <to.my.trociny@gmail.com>
# $FreeBSD$

PORTNAME=	netbsd-pkgsrc-mk-files
PORTVERSION=	20100117
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.mova.org/~cheusov/pub/netbsd-tools/pkgsrc-mk-files/ \
		http://trociny.googlecode.com/files/

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Collection of mk-files from pkgsrc project

DEPRECATED=	Imported for devel/mk-configure but no longer required
EXPIRATION_DATE=	2013-11-20

RUN_DEPENDS=	bmake:${PORTSDIR}/devel/bmake

USE_BZIP2=	YES
DATADIR=	${PREFIX}/share/netbsd-pkgsrc-mk
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	cd ${WRKSRC} && \
	${MKDIR} ${DATADIR} && \
	MK_DST=${DATADIR} OPSYS=FreeBSD SYSCONFDIR=${PREFIX}/etc \
	ROOT_GROUP=wheel ROOT_USER=root \
	CP=cp SED=sed \
	${SH} bootstrap.sh

.include <bsd.port.mk>
