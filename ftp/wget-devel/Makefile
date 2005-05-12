# Ports collection makefile for:  wget-devel
# Date created:			  10 january 2004
# Whom:				  Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	wget
DISTVERSION=	1.10-beta1
CATEGORIES=	ftp www ipv6
#MASTER_SITES=	${MASTER_SITE_GNU}
#MASTER_SITE_SUBDIR=	wget
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sf
PKGNAMESUFFIX=	-devel

MAINTAINER=	sf@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP and FTP

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif

CONFLICTS=	wget-1.8*

USE_BZIP2=		yes
USE_REINPLACE=		yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=		yes

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=		--with-ssl=no
.else
USE_OPENSSL=	yes
.endif
PLIST_SUB=	NLS=""
.if !defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--enable-nls
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		"LDFLAGS=${LDFLAGS}"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
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
