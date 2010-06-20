# New ports collection makefile for:	lftp
# Date created:				11 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	lftp
PORTVERSION=	4.0.9
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/old/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/ftp/lftp/ \
		http://lftp.cybermirror.org/ \
		http://lftp.cybermirror.org/old/ \
		ftp://ftp.wiretapped.net/pub/mirrors/lftp/ \
		ftp://ftp.wiretapped.net/pub/mirrors/lftp/old/ \
		ftp://ftp.yars.free.net/pub/source/lftp/ \
		ftp://ftp.yars.free.net/pub/source/lftp/old/
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Shell-like command line ftp client

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_ICONV=	yes
USE_XZ=		yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS BUGS ChangeLog FAQ FEATURES INSTALL \
		MIRRORS NEWS README README.debug-levels README.modules \
		THANKS TODO

OPTIONS=	OPENSSL "With OpenSSL support" on \
		GNUTLS "With GnutTLS support" off \
		NLS "With i18n support" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602109 || (${OSVERSION} > 700000 && ${OSVERSION} < 700029)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libreadline.so.6:${PORTSDIR}/devel/readline
RUN_DEPENDS+=	${LOCALBASE}/lib/libreadline.so.6:${PORTSDIR}/devel/readline
.endif

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		lftp.1 lftpget.1
MAN5=		lftp.conf.5

pre-configure:
.if !defined(WITHOUT_OPENSSL) && defined(WITH_GNUTLS)
	@${ECHO_MSG} "========"
	@${ECHO_MSG} "WARNING: both OPENSSL and GNUTLS have been selected, OPENSSL will be used"
	@${ECHO_MSG} "========"
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf.sample
	@if [ ! -f ${PREFIX}/etc/lftp.conf ]; then \
	${CP} -p ${PREFIX}/etc/lftp.conf.sample ${PREFIX}/etc/lftp.conf ; \
	fi

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
