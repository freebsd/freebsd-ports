# $FreeBSD$

PORTNAME=	ajaxzip2
PORTVERSION=	20140228
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMESUFFIX=	-data
DISTFILES=	ken_all-${PORTVERSION_K}.lzh jigyosyo-${PORTVERSION_J}.lzh

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	ajaxzip2 (Japanese ZIP code utility) ZIP data

BUILD_DEPENDS=	ja-ajaxzip2-core>0:${PORTSDIR}/japanese/ajaxzip2-core \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON

NO_WRKSUBDIR=	yes
USES=		perl5 lha
USE_PERL5=	build
PORTVERSION_K?=	${PORTVERSION}
PORTVERSION_J?=	${PORTVERSION}

do-build:
	${MKDIR} ${WRKSRC}/data ${WRKSRC}/work
	cd ${WRKSRC}/work && ${DATADIR}/csv2jsonzip.pl ../ken_all.csv ../jigyosyo.csv

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	cd ${WRKSRC}/data && ${INSTALL_DATA} zip-???.json ${STAGEDIR}${DATADIR}/data/

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
