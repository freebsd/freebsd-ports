# New ports collection makefile for:	lftp
# Date created:				11 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	lftp
PORTVERSION=	2.6.12
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.phear.org/pub/linux/networking/ftp/client/lftp/ \
		ftp://ftp.phear.org/pub/linux/networking/ftp/client/lftp/old/ \
		http://the.wiretapped.net/mirrors/lftp/ \
		http://the.wiretapped.net/mirrors/lftp/old/ \
		ftp://ftp.ayamura.org/pub/lftp/ \
		ftp://ftp.ayamura.org/pub/lftp/old/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/old/ \
		ftp://the.ausmac.net/pub/mirrors/lftp/ \
		ftp://the.ausmac.net/pub/mirrors/lftp/old/ \
		ftp://ftp.bme.hu/packages/lftp/ \
		ftp://ftp.bme.hu/packages/lftp/old/ \
		ftp://ftp.tuwien.ac.at/infosys/browsers/ftp/lftp/ \
		ftp://ftp.tuwien.ac.at/infosys/browsers/ftp/lftp/old/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/ftp/lftp/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/ftp/lftp/old/ \
		ftp://mirror.widexs.nl/pub/lftp/ \
		ftp://mirror.widexs.nl/pub/lftp/old/ \
		ftp://ftp.130th.net/pub/mirror/lftp/ \
		ftp://ftp.130th.net/pub/mirror/lftp/old/ \
		ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/ \
		ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/old/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fm@code.org.ua
COMMENT=	Shell-like command line ftp client

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.asc

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_SOCKS4)
CONFIGURE_ARGS+=	--with-socks
.endif
.if defined(WITH_SOCKS5)
CONFIGURE_ARGS+=	--with-socks5
.endif
.if defined(WITH_SOCKS_DANTE)
CONFIGURE_ARGS+=	--with-socksdante
.endif

MAN1=		lftp.1

post-install:
	@${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ifile in COPYING FAQ NEWS README README.debug-levels README.modules THANKS TODO FEATURES
	@${INSTALL_DATA} ${WRKSRC}/${ifile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
