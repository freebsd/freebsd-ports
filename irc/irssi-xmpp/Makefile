PORTNAME=	irssi-xmpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.54
PORTREVISION=	1
CATEGORIES=	irc

PATCH_SITES=	https://github.com/ailin-nemui/${PORTNAME}/commit/
PATCHFILES+=	f84cca86f6cbfa34.patch:-p1 # Use full paths to irssi includes
PATCHFILES+=	c7728ea5aa2f4e58.patch:-p1 # GTimeVal -> gint64 transition

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Irssi plugin to connect to Jabber network

LICENSE=	GPLv2

BUILD_DEPENDS=	irssi:irc/irssi
LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext-runtime gnome pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	cdidier

USE_GNOME=	glib20
USE_LDCONFIG=	yes

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
CFLAGS_aarch64=	-fPIC
CFLAGS_amd64=	-fPIC
CFLAGS_i386=	-fPIC
CFLAGS_powerpc64=	-fPIC

DATADIR=	${PREFIX}/share/irssi
DOCSDIR=	${PREFIX}/share/doc/irssi

OPTIONS_DEFINE=	DOCS

post-patch:
# Try to unbreak parallel builds (-jX)
	@${REINPLACE_CMD} -E 's|cd (.+) && (\$$\{MAKE})|\2 -C \1|' \
		${WRKSRC}/Makefile ${WRKSRC}/src/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/irssi/modules/*.so

.include <bsd.port.mk>
