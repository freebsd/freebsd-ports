# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yafc
PORTVERSION=	1.2.5
PORTREVISION=	4
CATEGORIES=	ftp
MASTER_SITES=	http://www.yafc-ftp.com/downloads/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Yet another FTP client, similar to ftp(1)

BROKEN=		unfetchable

LICENSE=	GPLv2+

OPTIONS_DEFINE=	BASH EXAMPLES NLS SSH READLINE
OPTIONS_DEFAULT=BASH SSH

USES=		gmake tar:xz ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_ipv6=yes
CONFIGURE_ARGS=	--with-socks=no --with-socks5=no --with-krb4=no \
		--with-krb5=no --with-openssl=${OPENSSLBASE}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTEXAMPLES=	inputrc yafcrc
PLIST_FILES=	bin/yafc \
		man/man1/yafc.1.gz
INFO=		yafc

NLS_USES=		gettext
NLS_USE=		GNOME=intltool
NLS_CONFIGURE_WITH=	gettext=${LOCALBASE}
NLS_PLIST_FILES=	share/locale/de/LC_MESSAGES/yafc.mo \
			share/locale/sv/LC_MESSAGES/yafc.mo

READLINE_USES=		readline
READLINE_CONFIGURE_WITH=readline

SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CONFIGURE_OFF=	--without-ssh

BASH_CONFIGURE_ON=	--with-bash-completion=yes
BASH_PLIST_FILES=	etc/bash_completion.d/yafc
BASH_CONFIGURE_OFF=	--with-bash-completion=no

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
