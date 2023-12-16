PORTNAME=	public_suffix_list
PORTVERSION=	20231128
CATEGORIES=	dns

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Public Suffix List by Mozilla
WWW=		https://publicsuffix.org/ \
		https://github.com/publicsuffix/list

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

SLAVEDIRS=	dns/p5-Mozilla-PublicSuffix dns/py-publicsuffix dns/py-publicsuffix2 dns/py-publicsuffixlist dns/rubygem-public_suffix dns/rubygem-public_suffix_service www/py-adblock

NO_ARCH=	yes
NO_BUILD=	yes

PORTDATA=	public_suffix_list.dat \
		test_psl.txt

USE_GITHUB=	yes
GH_ACCOUNT=	publicsuffix
GH_PROJECT=	list
GH_TAGNAME=	4969251

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/public_suffix_list.dat ${WRKSRC}/tests/test_psl.txt ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
