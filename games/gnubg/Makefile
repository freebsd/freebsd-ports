# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	gnubg
PORTVERSION=	1.02.000
CATEGORIES=	games
MASTER_SITES=	http://www.c-s.li/ports/ \
		http://files.gnubg.org/media/sources/
DISTFILES=	gnubg-release-${PORTVERSION}-sources.tar.gz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	GNU Backgammon

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		gdbm:${PORTSDIR}/databases/gdbm \
		png15:${PORTSDIR}/graphics/png \
		gtkextra-x11-2.0.1:${PORTSDIR}/x11-toolkits/gtkextra2 \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

OPTIONS_DEFINE=	ESOUND NLS
OPTIONS_DEFAULT=ESOUND NLS

CONFIGURE_ARGS=	--with-board3d

CONFIGURE_ENV=	ac_cv_path_ARTSC_CONFIG=no ac_cv_path_LIBART_CONFIG=no

INSTALLS_ICONS=	yes
USE_GNOME=	libxml2
USES=		gmake pathfix shebangfix
USE_PYTHON=	2.0+
USE_AUTOTOOLS=	libtool automake
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
.else
CONFIGURE_ENV+=	ac_cv_path_AUDIOFILE_CONFIG=no ac_cv_path_ESD_CONFIG=no
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=	--enable-nls
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
CONFIGURE_ARGS+=	--disable-sse
.endif

INFO=	gnubg

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|bin\/bash|${PREFIX}bin\/bash|g' ${WRKSRC}/scripts/query_player.sh

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include <bsd.port.mk>
