# Ports collection makefile for:  wget-devel
# Date created:			  10 january 2004
# Whom:				  Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	wget-devel
PORTVERSION=	1.9.1
CATEGORIES=	ftp www ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wget
DISTNAME=	wget-${PORTVERSION}

#PATCH_SITES=	${MASTER_SITE_LOCAL}
#PATCH_SITE_SUBDIR=	sf
#PATCHFILES=	wget_${PORTVERSION}-12.diff.gz
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP and FTP

.if !defined(WITHOUT_NLS)
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old
.endif

CONFLICTS=	wget-*

USE_REINPLACE=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=		--with-ssl=no
.else
USE_OPENSSL=	yes
.endif
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib
PLIST_SUB=	NLS=""
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

MAN1=		wget.1
INFO=		wget

post-patch:
	${RM} -f ${WRKSRC}/doc/wget.info*
# we don't need to run autoconf.
	${TOUCH} ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's,/etc/wgetrc,${PREFIX}/etc/wgetrc,' \
			 -e 's,@file{},@file{${PREFIX}},' \
		${WRKSRC}/doc/sample.wgetrc* ${WRKSRC}/doc/wget.texi

post-install:
	install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
