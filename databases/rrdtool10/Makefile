# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.0.50
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/rrdtool-1.0.x/
PKGNAMESUFFIX=	10

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Round Robin Database Tools

MAKE_ENV=	PERL=${PERL}

CONFLICTS=	rrdtool12-* rrdtool-1.*

USES=		pkgconfig perl5
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-local-zlib \
		--program-transform-name=''
CONFIGURE_ENV=	PERL=${PERL} PERL_MAKE_OPTIONS="PREFIX=${PREFIX}"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS:=	${CFLAGS:N-ffast-math}

MAN1=		RRDp.1 RRDs.1 bin_dec_hex.1 rrdcgi.1 rrdcreate.1 rrddump.1 \
		rrdfetch.1 rrdgraph.1 rrdlast.1 rrdresize.1 rrdrestore.1 \
		rrdtool.1 rrdtune.1 rrdtutorial.1 rrdtutorial.es.1 rrdupdate.1 \
		cdeftutorial.1 rpntutorial.1 rrdinfo.1 rrdxport.1 rrd-beginners.1 \
		rrdfirst.1
MAN3=		RRDp.3 RRDs.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}

OPTIONS_DEFINE=	LATIN2
LATIN2_DESC=	ISO-8859-2 fonts support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLATIN2}
CONFIGURE_ARGS+=--enable-latin2
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--with-pic
.endif

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

post-extract:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's/install-idocDATA install-ihtmlDATA//g' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "############################################################################"
	@${ECHO_MSG} "# See ${PREFIX}/share/examples/rrdtool for some demonstration code        #"
	@${ECHO_MSG} "############################################################################"
.endif

.include <bsd.port.mk>
