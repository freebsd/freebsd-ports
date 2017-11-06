# Created by: Jun-ichiro itojun Itoh <itojun@itojun.org>
# $FreeBSD$

PORTNAME=	nvi
PORTVERSION=	1.79.20040608
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	ftp://ftp.mk.bsdclub.org/pub/FreeBSD/distfiles/	\
		http://people.allbsd.org/~hrs/FreeBSD/
PKGNAMESUFFIX?=	-m17n
DISTNAME=	nvi-1.79

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	nvi-m17n-1.79-20040608.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of vi/ex, with multilingual patch, no default settings

LICENSE=	BSD4CLAUSE

PATCH_DIST_ARGS=	-d ${WRKSRC}/.. --forward --quiet -E -p0 -f
WRKSRC=		${WRKDIR}/${DISTNAME}/build

USES=		ncurses perl5
USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPTFLAG='-D_PATH_SYSEXRC=\"${PREFIX}/etc/vi.exrc\"' \
		vi_cv_path_perl=${PERL}
CONFIGURE_ARGS=	--program-prefix=n

OPTIONS_RADIO=	MULTIBYTE
OPTIONS_RADIO_MULTIBYTE=	EUC_JP EUC_CN EUC_KR ISO_8859_1 ISO_8859_2\
				ISO_8859_3 ISO_8859_4 ISO_8859_7 ISO_8859_8\
				ISO_8859_9 ISO_2022_CN ISO_2022_JP\
				ISO_2022_JP_3 ISO_2022_KR CTEXT\
				SJIS BIG5 EUC_TW
OPTIONS_DEFINE=		CANNA
OPTIONS_DEFAULT=
EUC_JP_DESC=		Set euc-jp        as default multibyte encoding
EUC_CN_DESC=		Set euc-cn        as default multibyte encoding
EUC_KR_DESC=		Set euc-kr        as default multibyte encoding
ISO_8859_1_DESC=	Set iso-8859-1    as default multibyte encoding
ISO_8859_2_DESC=	Set iso-8859-2    as default multibyte encoding
ISO_8859_3_DESC=	Set iso-8859-3    as default multibyte encoding
ISO_8859_4_DESC=	Set iso-8859-4    as default multibyte encoding
ISO_8859_7_DESC=	Set iso-8859-7    as default multibyte encoding
ISO_8859_8_DESC=	Set iso-8859-8    as default multibyte encoding
ISO_8859_9_DESC=	Set iso-8859-9    as default multibyte encoding
ISO_2022_CN_DESC=	Set iso-2022-cn   as default multibyte encoding
ISO_2022_JP_DESC=	Set iso-2022-jp   as default multibyte encoding
ISO_2022_JP_3_DESC=	Set iso-2022-jp-3 as default multibyte encoding
ISO_2022_KR_DESC=	Set iso-2022-kr   as default multibyte encoding
CTEXT_DESC=		Set X11 compound  as default multibyte encoding
SJIS_DESC=		Set sjis          as default multibyte encoding
BIG5_DESC=		Set big5          as default multibyte encoding
EUC_TW_DESC=		Set euc-tw        as default multibyte encoding
CANNA_DESC=		Enable canna support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MEUC_JP}
CONFIGURE_ARGS+=	--enable-multibyte=euc-jp
.elif ${PORT_OPTIONS:MEUC_CN}
CONFIGURE_ARGS+=	--enable-multibyte=euc-cn
.elif ${PORT_OPTIONS:MEUC_KR}
CONFIGURE_ARGS+=	--enable-multibyte=euc-kr
.elif ${PORT_OPTIONS:MISO_8859_1}
CONFIGURE_ARGS+=	--enable-multibyte=iso-8859-1
.elif ${PORT_OPTIONS:MISO_8859_2}
CONFIGURE_ARGS+=	--enable-multibyte=iso-8859-2
.elif ${PORT_OPTIONS:MISO_8859_3}
CONFIGURE_ARGS+=	--enable-multibyte=iso-8859-3
.elif ${PORT_OPTIONS:MISO_8859_4}
CONFIGURE_ARGS+=	--enable-multibyte=iso-8859-4
.elif ${PORT_OPTIONS:MISO_8859_7}
CONFIGURE_ARGS+=	--enable-multibyte=iso-8859-7
.elif ${PORT_OPTIONS:MISO_8859_8}
CONFIGURE_ARGS+=	--enable-multibyte=iso-8859-8
.elif ${PORT_OPTIONS:MISO_8859_9}
CONFIGURE_ARGS+=	--enable-multibyte=iso-8859-9
.elif ${PORT_OPTIONS:MISO_2022_CN}
CONFIGURE_ARGS+=	--enable-multibyte=iso-2022-cn
.elif ${PORT_OPTIONS:MISO_2022_JP}
CONFIGURE_ARGS+=	--enable-multibyte=iso-2022-jp
.elif ${PORT_OPTIONS:MISO_2022_JP_3}
CONFIGURE_ARGS+=	--enable-multibyte=iso-2022-jp-3
.elif ${PORT_OPTIONS:MISO_2022_KR}
CONFIGURE_ARGS+=	--enable-multibyte=iso-2022-kr
.elif ${PORT_OPTIONS:MCTEXT}
CONFIGURE_ARGS+=	--enable-multibyte=ctext
.elif ${PORT_OPTIONS:MSJIS}
CONFIGURE_ARGS+=	--enable-multibyte=sjis
.elif ${PORT_OPTIONS:MBIG5}
CONFIGURE_ARGS+=	--enable-multibyte=big5
.elif ${PORT_OPTIONS:MEUC_TW}
CONFIGURE_ARGS+=	--enable-multibyte=euc-tw
.else
CONFIGURE_ARGS+=	--enable-multibyte
.endif

.if ${PORT_OPTIONS:MCANNA}
CONFIGURE_ARGS+=	--enable-canna=${PREFIX}
LIB_DEPENDS=	libcanna.so:japanese/canna-lib
.endif

post-patch:
	${LN} -s /usr/include/sys/queue.h ${WRKSRC}/../include/sys/queue_dist.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/../docs.m17n/README.english \
		${STAGEDIR}${PREFIX}/share/vi/
	${INSTALL_DATA} ${WRKSRC}/../docs.m17n/README.japanese \
		${STAGEDIR}${PREFIX}/share/vi/

.include <bsd.port.post.mk>
