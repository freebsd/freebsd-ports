PORTNAME=	mecab-ipadic
DISTVERSION=	2.7.0-20070801
PORTREVISION=	3
CATEGORIES=	japanese textproc
MASTER_SITES=	http://downloads.sourceforge.net/mecab/ \
		https://github.com/PROoshio/mecab/raw/master/

MAINTAINER=	mce@FreeBSD.org
COMMENT?=	MeCab IPA dictionary meta-port
WWW=		https://taku910.github.io/mecab/

.if empty(PKGNAMESUFFIX)
USES=		metaport
OPTIONS_SINGLE=	CHARSET
OPTIONS_SINGLE_CHARSET=	EUCJP SHIFTJIS UTF8
OPTIONS_DEFAULT=UTF8
EUCJP_DESC=	Use EUC-JP as dictionary charset
SHIFTJIS_DESC=	Use SHIFT-JIS as dictionary charset
UTF8_DESC=	Use UTF-8 as dictionary charset

EUCJP_RUN_DEPENDS=	ja-mecab-ipadic-eucjp>0:japanese/mecab-ipadic-eucjp
SHIFTJIS_RUN_DEPENDS=	ja-mecab-ipadic-sjis>0:japanese/mecab-ipadic-sjis
UTF8_RUN_DEPENDS=	ja-mecab-ipadic-utf8>0:japanese/mecab-ipadic-utf8

.else

LICENSE=	NAIST ICOT
LICENSE_COMB=	multi
LICENSE_NAME_NAIST=	NAIST
LICENSE_NAME_ICOT=	ICOT
LICENSE_PERMS_NAIST=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ICOT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_NAIST=	${WRKSRC}/COPYING
LICENSE_FILE_ICOT=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ja-mecab>0:japanese/mecab

USES=		perl5
USE_PERL5=	build

CONFIGURE_ARGS=	--with-charset=${CSET} \
		--with-dicdir=${PREFIX}/lib/mecab/dic/ipadic
GNU_CONFIGURE=	yes
NO_ARCH=	yes
PORTSCOUT=	skipv:3.0.0-00000000,4.0.0-00000000,5.0.0-00000000
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST=		${MASTERDIR}/pkg-plist.cset

CONFLICTS_INSTALL=	ja-mecab-ipadic-[^0-9]*
.endif

.include <bsd.port.mk>
