PORTNAME=	unidic-to-mozc
DISTVERSION=	1.1.0
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/jassdack/UniDic-to-Mozc/releases/download/v${DISTVERSION}/
DISTFILES=	mozc_unidic_merged_v${DISTVERSION}.zip \
		mozc_unidic_names_v${DISTVERSION}.zip

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Auxiliary dictionary containing the words Mozc cannot convert
WWW=		https://github.com/jassdack/UniDic-to-Mozc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/UNIDIC_LICENSE.txt

USES=		zip

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

NO_WRKSUBDIR=	yes

PORTDATA=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in merged names
	${INSTALL_DATA} ${WRKSRC}/mozc_unidic_$i_1.tsv \
		${STAGEDIR}${DATADIR}/mozc_unidic_$i_1.txt
.endfor

.include <bsd.port.mk>
