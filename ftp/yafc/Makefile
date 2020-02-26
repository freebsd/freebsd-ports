# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yafc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.7
CATEGORIES=	ftp

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Yet another FTP client, similar to ftp(1)

LICENSE=	GPLv2+

BUILD_DEPENDS=	glib>0:devel/glib20

USES=		autoreconf gmake makeinfo pkgconfig ssl tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	sebastinas

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-krb5=no \
		--with-openssl=${OPENSSLBASE} \
		--with-socks5=no \
		--with-socks=no
CONFIGURE_ENV=	ac_cv_ipv6=yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		yafc
PLIST_FILES=	bin/yafc \
		man/man1/yafc.1.gz
PORTEXAMPLES=	inputrc yafcrc

OPTIONS_DEFINE=		BASH EXAMPLES NLS READLINE SSH
OPTIONS_DEFAULT=	BASH SSH

BASH_CONFIGURE_OFF=	--with-bash-completion=no
BASH_CONFIGURE_ON=	--with-bash-completion=yes
BASH_PLIST_FILES=	etc/bash_completion.d/yafc

NLS_USES=		gettext gnome
NLS_USE=		GNOME=intltool
NLS_CONFIGURE_WITH=	gettext=${LOCALBASE}
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/yafc.mo \
			share/locale/sv/LC_MESSAGES/yafc.mo

READLINE_USES=			readline
READLINE_CONFIGURE_WITH=	readline

SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CONFIGURE_OFF=	--without-ssh

pre-configure-NLS-on:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/glib-gettextize -f -c)

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
