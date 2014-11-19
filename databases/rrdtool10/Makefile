# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.0.50
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/rrdtool-1.0.x/
PKGNAMESUFFIX=	10

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Round Robin Database Tools

LICENSE=	GPLv2

MAKE_ENV=	PERL=${PERL}

CONFLICTS=	rrdtool12-1.* rrdtool-1.*

USES=		pkgconfig perl5 libtool
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f
USE_PERL5=	build run fixpacklist
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-local-zlib
CONFIGURE_ENV=	PERL=${PERL} PERL_MAKE_OPTIONS="PREFIX=${PREFIX}"
CFLAGS:=	${CFLAGS:N-ffast-math}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	LATIN2 DOCS EXAMPLES
LATIN2_DESC=	ISO-8859-2 fonts support

LATIN2_CONFIGURE_ENABLE=	latin2

post-patch:
# fix perl5.18+ pod2x tool
	${REINPLACE_CMD} -e 's|IMG<|IMG ... E<|' \
		${WRKSRC}/doc/rrdcgi.pod
	${REINPLACE_CMD} -e 's|rrdtutorial.es.pod||' \
		${WRKSRC}/doc/Makefile.am \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
