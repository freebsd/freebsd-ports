PORTNAME=	unidic-to-mozc
DISTVERSION=	1.0.0
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/jassdack/UniDic-to-Mozc/releases/download/v${DISTVERSION}/
DISTNAME=	mozc_unidic_merged_v${DISTVERSION}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Mozc user dictionary integration
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
.for i in 1 2 3 4
	@${MV} ${WRKSRC}/mozc_unidic_merged_$i.tsv \
		${WRKSRC}/mozc_unidic_merged_$i.txt
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mozc_unidic_merged_*.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
