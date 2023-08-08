PORTNAME=	zipcodes
PORTVERSION=	20221228
CATEGORIES=	japanese
MASTER_SITES=	LOCAL/hrs
DISTFILES=	ken_all-${PORTVERSION_K}.zip jigyosyo-${PORTVERSION_J}.zip

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese zipcode tables. includes both 3/5 and 7 digits form
WWW=		https://www.post.japanpost.jp/zipcode/

LICENSE=	PD

BUILD_DEPENDS=	nkf:japanese/nkf

USES=		perl5 zip
USE_PERL5=	build

NO_WRKSUBDIR=	yes
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		SCRIPTDIR=${SCRIPTDIR} \
		PERL=${PERL} \
		STAGEDIR=${STAGEDIR}
MAKEFILE=	${FILESDIR}/Makefile
PLIST_FILES=	share/misc/jp-zipcodes/jigyosyo-euc.csv \
		share/misc/jp-zipcodes/ken_all-euc.csv \
		share/misc/jp-zipcodes/zipcodes.5digits \
		share/misc/jp-zipcodes/zipcodes.7digits
PORTVERSION_K?=	${PORTVERSION}
PORTVERSION_J?=	${PORTVERSION}

post-extract:
	cd ${WRKSRC} && \
	    ${MV} KEN_ALL.CSV ken_all.csv && \
	    ${MV} JIGYOSYO.CSV jigyosyo.csv

.include <bsd.port.mk>
