# New ports collection makefile for:   see
# Date created:        22 September 2004
# Whom:                numisemis@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	see
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://www.adaptive-enterprises.com.au/~d/software/see/

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Simple ECMAScript Engine (SEE)

CONFLICTS=	see-devel-[0-9]*

OPTIONS=	GC "Use Boehm-Weiser garbage collection pkg" on \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fomit-frame-pointer
.endif

.if !defined(WITHOUT_GC)
LIB_DEPENDS+=	gc:${PORTSDIR}/devel/boehm-gc
.else
CONFIGURE_ARGS+=	--without-boehm-gc
PTHREAD_CFLAGS=
PTHREAD_LIBS=
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|PACKAGE_BUGREPORT='leonard@users|PACKAGE_BUGREPORT='leonard\\\@users|" \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in doc/USAGE.html AUTHORS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
