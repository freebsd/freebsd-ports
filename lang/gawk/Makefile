# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	gawk
PORTVERSION=	4.1.0
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The GNU version of Awk

LIB_DEPENDS=	libsigsegv.so:${PORTSDIR}/devel/libsigsegv

OPTIONS_DEFINE=		NLS MPFR
OPTIONS_SUB=		yes
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
MPFR_DESC?=		Support multiple-precision floating-point computation
MPFR_LIB_DEPENDS=	libmpfr.so:${PORTSDIR}/math/mpfr
MPFR_CONFIGURE_OFF=	--without-gmp --without-mpfr

INFO=		gawk gawkinet

USE_XZ=		true
GNU_CONFIGURE=	yes
USES=		iconv
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-libintl-prefix=${LOCALBASE} \
		AWK=${AWK}

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${RM} -f ${WRKSRC}/doc/*.info
	@${REINPLACE_CMD} -e 's/ -export-dynamic/ -Wl,--export-dynamic/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
