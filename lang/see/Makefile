# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	see
PORTVERSION=	2.0.1131
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://www.powerband.net.au/~david.leonard/ \
		http://freshmeat.net/redir/see/45974/url_tgz/

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Simple ECMAScript Engine (SEE)

OPTIONS_DEFINE=	GC OPTIMIZED_CFLAGS SEE_DEBUG THREADS DOCS
OPTIONS_DEFAULT=	GC THREADS
GC_DESC=	Use Boehm-Weiser garbage collection package
SEE_DEBUG_DESC=	Internal SEE library debugging

CONFLICTS=	see-devel-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

USE_LDCONFIG=	yes
USES=		perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMULTIPLE_THREADS}
CFLAGS+=	-DMULTIPLE_THREADS
.endif

.if ! ${PORT_OPTIONS:MSEE_DEBUG}
CFLAGS+=	-DNDEBUG
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer
.endif

.if ${PORT_OPTIONS:MGC}
LIB_DEPENDS+=	gc:${PORTSDIR}/devel/boehm-gc
.else
CONFIGURE_ARGS+=	--without-boehm-gc
.if ! ${PORT_OPTIONS:MTHREADS}
PTHREAD_CFLAGS=
PTHREAD_LIBS=
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|PACKAGE_BUGREPORT='leonard@users|PACKAGE_BUGREPORT='leonard\\\@users|" \
		${WRKSRC}/configure

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in doc/USAGE.html AUTHORS NEWS README TODO COPYING
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
