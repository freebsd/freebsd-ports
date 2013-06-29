# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	gawk
PORTVERSION=	4.1.0
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The GNU version of Awk

LIB_DEPENDS=	sigsegv:${PORTSDIR}/devel/libsigsegv

OPTIONS_DEFINE=	MPFR
MPFR_DESC?=	Support multiple-precision floating-point computation

INFO=		gawk gawkinet

USE_XZ=		true
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		AWK=${AWK}

MAN1=		gawk.1 igawk.1
MAN3=		filefuncs.3am fnmatch.3am fork.3am ordchr.3am readdir.3am \
		readfile.3am revoutput.3am revtwoway.3am rwarray.3am time.3am

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MMPFR}
LIB_DEPENDS=	mpfr:${PORTSDIR}/math/mpfr
.else
CONFIGURE_ARGS+=--without-gmp --without-mpfr
.endif

post-patch:
	@${RM} -f ${WRKSRC}/doc/*.info
	@${REINPLACE_CMD} -e 's/ -export-dynamic/ -Wl,--export-dynamic/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
