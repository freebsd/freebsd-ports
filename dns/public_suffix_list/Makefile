# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	public_suffix_list
PORTVERSION=	20190803
CATEGORIES=	dns

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Public Suffix List by Mozilla

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

SLAVEDIRS=	dns/p5-Mozilla-PublicSuffix dns/py-publicsuffix dns/py-publicsuffixlist dns/rubygem-public_suffix dns/rubygem-public_suffix_service

NO_ARCH=	yes
NO_BUILD=	yes

PORTDATA=	public_suffix_list.dat \
		test_psl.txt

GH_ACCOUNT=	publicsuffix
GH_PROJECT=	list
GH_TAGNAME=	605a66a
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/public_suffix_list.dat ${WRKSRC}/tests/test_psl.txt ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
