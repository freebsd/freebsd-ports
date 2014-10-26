# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	1.0.50
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://oss.oetiker.ch/rrdtool/pub/rrdtool-1.0.x/
PKGNAMESUFFIX=	10

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Round Robin Database Tools

MAKE_ENV=	PERL=${PERL}

CONFLICTS=	rrdtool12-* rrdtool-1.*

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

.include <bsd.port.pre.mk>

.if ${PERL_VER} >= 5.18
BROKEN=		Does not build with Perl 5.18 or above
.endif

.include <bsd.port.post.mk>
