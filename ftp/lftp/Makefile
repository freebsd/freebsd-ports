# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	lftp
PORTVERSION=	4.4.1
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://ftp.yars.free.net/pub/source/lftp/ \
		http://ftp.yars.free.net/pub/source/lftp/old/ \
		http://lftp.cybermirror.org/ \
		http://lftp.cybermirror.org/old/ \
		http://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/ \
		http://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/old/ \
		http://ftp.tuwien.ac.at/infosys/browsers/ftp/lftp/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/ftp/lftp/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Shell-like command line ftp client

LICENSE=	GPLv3

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

USE_ICONV=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
# XXX FreeBSD 9.x has posix_fallocate() for OSVERSION > 900035,
# but is missing the required POSIX_FADV_* macros
CONFIGURE_ENV=	i_cv_posix_fallocate_works=no \
		LIBS="-L${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS BUGS ChangeLog FAQ FEATURES INSTALL \
		MIRRORS NEWS README README.debug-levels README.modules \
		THANKS TODO

OPTIONS_DEFINE=	NLS
OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	OPENSSL GNUTLS
OPTIONS_DEFAULT=	SSL OPENSSL NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls
.else
CONFIGURE_ARGS+=	--without-gnutls
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

MAN1=		lftp.1 lftpget.1
MAN5=		lftp.conf.5

post-install:
	@${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf.sample
.if !exists(${PREFIX}/etc/lftp.conf)
	${CP} -p ${PREFIX}/etc/lftp.conf.sample ${PREFIX}/etc/lftp.conf
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
