# New ports collection makefile for:   see
# Date created:        22 September 2004
# Whom:                sime@logos.hr
#
# $FreeBSD$
#

PORTNAME=	see
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.netsw.org/softeng/lang/js/ \
		http://www.adaptive-enterprises.com.au/~d/software/see/

MAINTAINER=	sime@logos.hr
COMMENT=	Simple ECMAScript Engine (SEE)

OPTIONS=	GC "Use Boehm-Weiser garbage collection package" on \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}"

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
.for f in doc/USAGE.html AUTHORS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
