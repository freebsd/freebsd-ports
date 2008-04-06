# New ports collection makefile for:   see-devel
# Date created:        29 Oct 2005
# Whom:                Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	see
PORTVERSION=	3.0.1376
CATEGORIES=	lang devel
MASTER_SITES=	http://www.evolane.com/download/mirror/etcl/ \
		http://www.evolane.fr/download/mirror/etcl/
PKGNAMESUFFIX=	-devel

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Simple ECMAScript Engine (SEE)

OPTIONS=	GC "Use Boehm-Weiser garbage collection package" on \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off \
		SEE_DEBUG "Internal SEE library debugging" off

CONFLICTS=	see-[0-9]*

USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if !defined(WITH_SEE_DEBUG)
CFLAGS+=	-DNDEBUG
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fomit-frame-pointer
.endif

.if defined(WITH_GC)
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
.for f in doc/USAGE.html AUTHORS NEWS README TODO COPYING
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
