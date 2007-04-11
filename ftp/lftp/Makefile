# New ports collection makefile for:	lftp
# Date created:				11 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	lftp
PORTVERSION=	3.5.10
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.wiretapped.net/pub/mirrors/lftp/ \
		ftp://ftp.wiretapped.net/pub/mirrors/lftp/old/ \
		ftp://ftp.130th.net/pub/mirror/lftp/ \
		ftp://ftp.130th.net/pub/mirror/lftp/old/ \
		ftp://ftp.iasi.roedu.net/pub/os/Linux/network/ftp/lftp/ \
		ftp://ftp.iasi.roedu.net/pub/os/Linux/network/ftp/lftp/old/ \
		ftp://ftp.yars.free.net/pub/source/lftp/ \
		ftp://ftp.yars.free.net/pub/source/lftp/old/ \
		ftp://lftp.yar.ru/lftp/ \
		ftp://lftp.yar.ru/lftp/old/

MAINTAINER=	fm@cross-road.org.ua
COMMENT=	Shell-like command line ftp client

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS+=	${LOCALBASE}/lib/libreadline.so.5:${PORTSDIR}/devel/readline
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_ICONV=	yes
USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

OPTIONS=	GNUTLS "With GnutTLS support" off \
		OPENSSL "With OpenSSL support" on \
		NLS "With i18n support" on

.include <bsd.port.pre.mk>

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--with-gnutls
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
.endif

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

CONFIGURE_ARGS+=--mandir="${MAN1PREFIX}/man"

MAN1=		lftp.1 lftpget.1

post-install:
	@${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ifile in COPYING FAQ NEWS README README.debug-levels README.modules THANKS TODO FEATURES
	@${INSTALL_DATA} ${WRKSRC}/${ifile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
