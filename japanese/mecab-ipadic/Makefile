# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	mecab-ipadic
DISTVERSION=	2.7.0-20070801
CATEGORIES=	japanese textproc
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	mecab

MAINTAINER=	yasu@utahime.org
COMMENT=	Japanese Morphological Dictionary for MeCab

LICENSE=	NAIST ICOT
LICENSE_COMB=	multi
LICENSE_NAME_NAIST=	NAIST
LICENSE_NAME_ICOT=	ICOT
LICENSE_FILE_NAIST=	${WRKSRC}/COPYING
LICENSE_FILE_ICOT=	${WRKSRC}/COPYING
LICENSE_PERMS_NAIST=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_ICOT=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	ja-mecab>=0.94:${PORTSDIR}/japanese/mecab

USES=			perl5
USE_PERL5=		build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-dicdir=${PREFIX}/lib/mecab/dic/ipadic

OPTIONS_RADIO=	CHARSET
OPTIONS_RADIO_CHARSET=	EUCJP SHIFTJIS UTF8

EUCJP_DESC=	Use EUC-JP as dictionary charset.
SHIFTJIS_DESC=	Use SHIFT-JIS as dictionary charset.
UTF8_DESC=	Use UTF-8 as dictionary charset.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEUCJP}
CONFIGURE_ARGS+=	--with-charset=euc-jp
.elif ${PORT_OPTIONS:MSHIFTJIS}
CONFIGURE_ARGS+=	--with-charset=shift_jis
.elif ${PORT_OPTIONS:MUTF8}
CONFIGURE_ARGS+=	--with-charset=utf-8
.endif

.include <bsd.port.mk>
