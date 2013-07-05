# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yafc
PORTVERSION=	1.2.5
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://www.yafc-ftp.com/upload/

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Yet another ftp client. Similar to ftp(1)

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	BASH EXAMPLES NLS SSH READLINE
OPTIONS_DEFAULT=BASH NLS SSH

USES=		gmake
USE_XZ=		yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_ipv6=yes
CONFIGURE_ARGS=	--with-socks=no --with-socks5=no --with-krb4=no \
		--with-krb5=no --with-openssl=${OPENSSLBASE}
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		yafc.1
INFO=		yafc
PORTEXAMPLES=	inputrc yafcrc
PLIST_FILES=	bin/yafc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GNOME+=	intltool
USES+=		gettext
CONFIGURE_ARGS+=	--with-gettext=${LOCALBASE}
PLIST_FILES+=	share/locale/de/LC_MESSAGES/yafc.mo \
		share/locale/sv/LC_MESSAGES/yafc.mo
.else
CONFIGURE_ARGS+=	--without-gettext
.endif

.if ${PORT_OPTIONS:MREADLINE}
USES+=		readline
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if ${PORT_OPTIONS:MSSH}
LIB_DEPENDS+=	ssh:${PORTSDIR}/security/libssh
.else
CONFIGURE_ARGS+=	--without-ssh
.endif

.if ${PORT_OPTIONS:MBASH}
CONFIGURE_ARGS+=	--with-bash-completion=yes
PLIST_FILES+=		etc/bash_completion.d/yafc
PLIST_DIRSTRY=		etc/bash_completion.d
.else
CONFIGURE_ARGS+=	--with-bash-completion=no
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
