# $FreeBSD$

PORTNAME=	zipcodes
PORTVERSION=	20140228
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
DISTFILES=	ken_all-${PORTVERSION_K}.lzh jigyosyo-${PORTVERSION_J}.lzh

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Japanese zipcode tables. includes both 3/5 and 7 digits form

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

NO_WRKSUBDIR=	yes

USES=		perl5 lha
USE_PERL5=	build
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" SCRIPTDIR=${SCRIPTDIR} PERL=${PERL} STAGEDIR=${STAGEDIR}
PORTVERSION_K?=	${PORTVERSION}
PORTVERSION_J?=	${PORTVERSION}

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

# for maintenance.
fetch1:
	fetch http://www.post.japanpost.jp/zipcode/dl/kogaki/lzh/ken_all.lzh
	fetch http://www.post.japanpost.jp/zipcode/dl/jigyosyo/lzh/jigyosyo.lzh
	${CHMOD} og+r *.lzh

fetch2:
	m=`stat -f %m ken_all.lzh`; \
	${MV} ken_all.lzh `date -r $${m} +ken_all-%Y%m%d.lzh`
	m=`stat -f %m jigyosyo.lzh`; \
	${MV} jigyosyo.lzh `date -r $${m} +jigyosyo-%Y%m%d.lzh`

.include <bsd.port.mk>
