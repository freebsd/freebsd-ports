# New ports collection makefile for:   see-devel
# Date created:        29 Oct 2005
# Whom:                Simun Mikecin <sime@logos.hr>
#
# $FreeBSD$
#

PORTNAME=	see
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	ftp://ftp.osuosl.org/pub/FreeBSD/distfiles/ \
		http://mirror.arcticnetwork.ca/pub/FreeBSD/distfiles/ \
		http://ftp3.ie.freebsd.org/pub/FreeBSD/distfiles/ \
		http://www.adaptive-enterprises.com.au/~d/software/see/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-20050609-gerry

MAINTAINER=	sime@logos.hr
COMMENT=	Simple ECMAScript Engine (SEE)

OPTIONS=	GC "Use Boehm-Weiser garbage collection package" on \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off

CONFLICTS=	see-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

USE_ZIP=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

.if defined(WITH_GC)
LIB_DEPENDS+=	gc:${PORTSDIR}/devel/boehm-gc
.else
CONFIGURE_ARGS+=	--without-boehm-gc
PTHREAD_CFLAGS=
PTHREAD_LIBS=
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|PACKAGE_BUGREPORT='dleonard@users|PACKAGE_BUGREPORT='dleonard\\\@users|" \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in doc/USAGE.html AUTHORS NEWS README TODO COPYING
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
