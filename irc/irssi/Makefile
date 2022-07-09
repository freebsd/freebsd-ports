PORTNAME=	irssi
DISTVERSION=	1.4.1
PORTEPOCH=	2
CATEGORIES?=	irc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

PATCH_SITES=	https://github.com/ailin-nemui/${PORTNAME}/commit/
PATCHFILES=	3404d822c83546b031d47a99e37ae65b887bec94.patch:-p1 \
		c6a7f02042f63d01a38e8d522cff8f5d951afd51.patch:-p1 \
		730c3c1a12f782b92d710883f52a106e37f148e4.patch:-p1 \
		1b6b92ffff6950ee28c1b7936f53d83988843ed4.patch:-p1

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Modular IRC client with many features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 cpe gettext-runtime gnome meson localbase:ldflags \
		ncurses perl5 pkgconfig ssl tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes

MESON_ARGS=	-Dinstall-glib=no -Ddisable-gregex=no -Dstatic-dependency=no \
		-Dwith-fuzzer=no -Dwithout-textui=no

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

PERL_USE_OFF=		perl5=build

post-install-PERL-off:
	@${RM} -r ${STAGEDIR}${DATADIR}/scripts

post-install:
	${INSTALL_DATA} ${WRKSRC}/irssi.conf ${STAGEDIR}${PREFIX}/etc/irssi.conf.sample

.include <bsd.port.mk>
