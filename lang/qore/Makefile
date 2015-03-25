# $FreeBSD$

PORTNAME=	qore
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/qore/qore/${PORTVERSION}/

MAINTAINER=	estrabd@gmail.com
COMMENT=	The Qore Programming Language

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libmpfr.so:${PORTSDIR}/math/mpfr
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		${LOCALBASE}/bin/bison:${PORTSDIR}/devel/bison

USES=		gmake iconv libtool pathfix tar:bzip2
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LEX="${LOCALBASE}/bin/flex" PTHREAD_LIBS="-lpthread"
CONFIGURE_ARGS=	--disable-debug --disable-static --with-doxygen=no
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

post-patch:
	${REINPLACE_CMD} -e 's|; make|; $${MAKE}|g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
