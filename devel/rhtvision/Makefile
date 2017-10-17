# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	rhtvision
PORTVERSION=	2.2.1.1
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	SF/tvision/UNIX/${PORTVERSION:R}%20CVS20100714%20Source%20and%20Debian%205.0
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete C++ Text User Interface (TUI) library

OPTIONS_DEFINE=	NLS X11
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/tvision

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	config.pl confignt.pl conflib.pl linux/compress
USE_GCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--real-prefix=${PREFIX} \
		--no-libs-here
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# The port does not build with C++11 or later (bug 219275).
USE_CXXSTD=     gnu++03

PLIST_SUB=	VERSION="${PORTVERSION:R}"

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--no-intl

X11_USE=		XORG=x11,xmu
X11_CONFIGURE_ON=	--x-include=${LOCALBASE}/include \
			--x-lib=${LOCALBASE}/lib
X11_CONFIGURE_OFF=	--X11lib=no

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rhtv-config \
		${STAGEDIR}${PREFIX}/lib/librhtv.so

.include <bsd.port.mk>
