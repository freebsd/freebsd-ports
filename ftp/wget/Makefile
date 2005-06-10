# Ports collection makefile for:  wget
# Date created:			  31 December 1996
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wget
DISTVERSION=	1.10
CATEGORIES=	ftp www ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wget

MAINTAINER=	sf@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP and FTP

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif

CONFLICTS=	wget-devel-[0-9]*

USE_REINPLACE=		yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=		yes

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=		--with-ssl=no
.else
USE_OPENSSL=	yes
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
CONFIGURE_ARGS+=	--enable-nls
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		"LDFLAGS=${LDFLAGS}"
PLIST_SUB=	NLS=""
.endif

MAN1=		wget.1
INFO=		wget

post-patch:
	${RM} -f ${WRKSRC}/doc/wget.info* ${WRKSRC}/po/*.mo ${WRKSRC}/po/*.gmo
# eliminate gmakism
	${REINPLACE_CMD} -e 's,$$<,$$(srcdir)/wget.texi,' \
		${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's,/etc/wgetrc,${PREFIX}/etc/wgetrc,' \
			 -e 's,@file{},@file{${PREFIX}},' \
		${WRKSRC}/doc/sample.wgetrc* ${WRKSRC}/doc/wget.texi

post-install:
	install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
