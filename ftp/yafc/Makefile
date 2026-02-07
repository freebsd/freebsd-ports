PORTNAME=	yafc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.7
PORTREVISION=	2
CATEGORIES=	ftp

MAINTAINER=	m.ne@gmx.net
COMMENT=	Yet another FTP client, similar to ftp(1)
WWW=		https://github.com/sebastinas/yafc

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib>0:devel/glib20

USES=		autoreconf gmake localbase pkgconfig ssl tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	sebastinas

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-krb5=no \
		--with-openssl=${OPENSSLBASE} \
		--with-socks5=no \
		--with-socks=no
CONFIGURE_ENV=	ac_cv_ipv6=yes

PLIST_FILES=	bin/yafc \
		share/man/man1/yafc.1.gz
PORTEXAMPLES=	inputrc yafcrc

OPTIONS_DEFINE=		BASH EXAMPLES INFO NLS READLINE SSH
OPTIONS_DEFAULT=	BASH INFO SSH

BASH_CONFIGURE_ON=	--with-bash-completion=yes
BASH_CONFIGURE_OFF=	--with-bash-completion=no
BASH_PLIST_FILES=	etc/bash_completion.d/yafc
INFO_USES=		makeinfo
INFO_INFO=		yafc
NLS_USES=		gettext gnome
NLS_USE=		GNOME=intltool
NLS_CONFIGURE_WITH=	gettext=${LOCALBASE}
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/yafc.mo \
			share/locale/sv/LC_MESSAGES/yafc.mo

READLINE_USES=			readline
READLINE_CONFIGURE_WITH=	readline

SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CONFIGURE_OFF=	--without-ssh

post-patch-INFO-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g' ${WRKSRC}/Makefile.am

pre-configure:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/glib-gettextize -f -c)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

post-install-INFO-off:
	${INSTALL_MAN} ${WRKSRC}/doc/yafc.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
