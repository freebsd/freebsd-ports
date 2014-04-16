# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	tme
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://people.csail.mit.edu/fredette/tme/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator for Sun 2/120, 3/150, and SPARCstation 2 machines

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler gmake gettext iconv perl5 pkgconfig
USE_GNOME=	gdkpixbuf2 gtk20
USE_AUTOTOOLS=	libtool libltdl
CONFIGURE_ENV=	ac_cv_have_isinff=no
CONFIGURE_ARGS=	--disable-warnings
USE_LDCONFIG=	yes
MAKE_ENV=	LANG=C
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${WRKSRC}/ic/ieee754/.libs
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-fbracket-depth=1024
.endif

post-patch:
	@${REINPLACE_CMD} -e '/misc_hosts/s|= no|= xno|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\.\./ieee754|$$(top_builddir)/ic/ieee754|g' \
		${WRKSRC}/ic/m68k/Makefile.in
	@${REINPLACE_CMD} -e 's|\.\./ieee754|$$(top_builddir)/ic/ieee754|g' \
		${WRKSRC}/ic/sparc/Makefile.in
	@${REINPLACE_CMD} -e '/^#ifdef/s|\*/||' \
		${WRKSRC}/libtme/misc.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/libtme/module.c

.include <bsd.port.post.mk>
