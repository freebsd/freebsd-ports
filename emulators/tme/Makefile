# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	tme
PORTVERSION=	0.8
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://people.csail.mit.edu/fredette/tme/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator for Sun 2/120, 3/150, and SPARCstation 2 machines

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		autoreconf compiler gettext gmake gnome iconv libtool perl5 \
		pkgconfig
USE_GNOME=	gdkpixbuf2 gtk20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --disable-warnings
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
MAKE_JOBS_UNSAFE=yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-fbracket-depth=1024
.endif

post-patch:
	@${RM} -r ${WRKSRC}/libltdl
	@${REINPLACE_CMD} 's/LTDL_SHLIBPATH_VAR/LT_MODULE_PATH_VAR/' \
		${WRKSRC}/libtme/Makefile.am ${WRKSRC}/libtme/module.c
	@${REINPLACE_CMD} -e '/^#ifdef/s|\*/||' \
		${WRKSRC}/libtme/misc.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/libtme/module.c

.include <bsd.port.post.mk>
