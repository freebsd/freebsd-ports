# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.0.50
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/rrdtool-1.0.x/
PKGNAMESUFFIX=	10

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Round Robin Database Tools

MAKE_ENV=	PERL=${PERL}

CONFLICTS=	rrdtool12-* rrdtool-1.*

USES=		pkgconfig perl5 libtool
USE_PERL5=	build run fixpacklist
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-local-zlib \
		--program-transform-name=''
CONFIGURE_ENV=	PERL=${PERL} PERL_MAKE_OPTIONS="PREFIX=${PREFIX}"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS:=	${CFLAGS:N-ffast-math}

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	LATIN2 DOCS EXAMPLES
LATIN2_DESC=	ISO-8859-2 fonts support

LATIN2_CONFIGURE_ENABLE=	latin2

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--with-pic
.endif

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "############################################################################"
	@${ECHO_MSG} "# See ${PREFIX}/share/examples/rrdtool for some demonstration code        #"
	@${ECHO_MSG} "############################################################################"
.endif

.include <bsd.port.mk>
