# $FreeBSD$

PORTNAME=	ajaxzip2
PORTVERSION=	20170428
CATEGORIES=	japanese
MASTER_SITES=	LOCAL/kuriyama
PKGNAMESUFFIX=	-data
DISTFILES=	ken_all-${PORTVERSION_K}.zip jigyosyo-${PORTVERSION_J}.zip

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	ajaxzip2 (Japanese ZIP code utility) ZIP data

BUILD_DEPENDS=	ja-ajaxzip2-core>0:japanese/ajaxzip2-core \
		p5-JSON>0:converters/p5-JSON

NO_WRKSUBDIR=	yes
USES=		perl5 zip
USE_PERL5=	build
PORTVERSION_K?=	${PORTVERSION}
PORTVERSION_J?=	${PORTVERSION}

do-build:
	${MKDIR} ${WRKSRC}/data ${WRKSRC}/work
	cd ${WRKSRC}/work && ${DATADIR}/csv2jsonzip.pl ../KEN_ALL.CSV ../JIGYOSYO.CSV

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/data
	cd ${WRKSRC}/data && ${INSTALL_DATA} zip-???.json ${STAGEDIR}${DATADIR}/data/

# for maintenance.
fetch1:
	fetch http://www.post.japanpost.jp/zipcode/dl/kogaki/zip/ken_all.zip
	fetch http://www.post.japanpost.jp/zipcode/dl/jigyosyo/zip/jigyosyo.zip
	${CHMOD} og+r *.zip

fetch2:
	m=`stat -f %m ken_all.zip`; \
	${MV} ken_all.zip `date -r $${m} +ken_all-%Y%m%d.zip`
	m=`stat -f %m jigyosyo.zip`; \
	${MV} jigyosyo.zip `date -r $${m} +jigyosyo-%Y%m%d.zip`

.include <bsd.port.mk>
