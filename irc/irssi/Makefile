# $FreeBSD$

PORTNAME=	irssi
DISTVERSION=	1.3-dev-344
DISTVERSIONSUFFIX=	-gf57dcfe9
PORTEPOCH=	1
CATEGORIES?=	irc

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Modular IRC client with many features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

# Until upstream makes a new release disable cpe
USES=		gettext-runtime gnome meson localbase:ldflags ncurses \
		perl5 pkgconfig ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	f57dcfe

MESON_ARGS=	-Dinstall-glib=no -Ddisable-gregex=no -Dstatic-dependency=no \
		-Dwith-fuzzer=no -Dwithout-textui=no

# Default linker (bfd) in FreeBSD 11 breaks compilation
LDFLAGS_FreeBSD_11=	-fuse-ld=lld

# Force OpenSSL from base
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto -lssl ${LDFLAGS_${OPSYS}_${OSREL:R}}

OPTIONS_DEFINE=		BOT CAPSICUM DOCS OTR PERL PROXY TRUECOLOR UTF8PROC
OPTIONS_DEFAULT=	BOT CAPSICUM PERL PROXY TRUECOLOR
OPTIONS_SUB=		yes

BOT_DESC=		Bot support
CAPSICUM_DESC=		Capsicum support
OTR_DESC=		OTR (off-the-record) support
TRUECOLOR_DESC=		True color support
UTF8PROC_DESC=		utf8proc support

BOT_MESON_YES=		with-bot
CAPSICUM_MESON_YES=	with-capsicum
OTR_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
			libotr.so:security/libotr
OTR_MESON_YES=		with-otr
PERL_MESON_YES=		with-perl
PROXY_MESON_YES=	with-proxy
TRUECOLOR_MESON_YES=	enable-true-color
UTF8PROC_LIB_DEPENDS=	libutf8proc.so:textproc/utf8proc
UTF8PROC_MESON_NO=	disable-utf8proc

post-install:
	@${MV} ${WRKSRC}/irssi.conf ${STAGEDIR}${PREFIX}/etc/irssi.conf.sample

.include <bsd.port.mk>
