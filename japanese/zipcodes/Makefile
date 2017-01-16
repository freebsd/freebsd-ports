# $FreeBSD$

PORTNAME=	zipcodes
PORTVERSION=	20161228
CATEGORIES=	japanese
MASTER_SITES=	LOCAL/kuriyama
DISTFILES=	ken_all-${PORTVERSION_K}.zip jigyosyo-${PORTVERSION_J}.zip

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Japanese zipcode tables. includes both 3/5 and 7 digits form

BUILD_DEPENDS=	nkf:japanese/nkf

NO_WRKSUBDIR=	yes

USES=		perl5 zip
USE_PERL5=	build
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" SCRIPTDIR=${SCRIPTDIR} PERL=${PERL} STAGEDIR=${STAGEDIR}
PORTVERSION_K?=	${PORTVERSION}
PORTVERSION_J?=	${PORTVERSION}

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	cd ${WRKSRC}; ${MV} KEN_ALL.CSV ken_all.csv; ${MV} JIGYOSYO.CSV jigyosyo.csv

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
