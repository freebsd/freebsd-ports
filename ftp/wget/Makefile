# Ports collection makefile for:  wget
# Date created:			  31 December 1996
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

# NOTE: I would like to skip wget-1.9 and wait for stabilization.
#       Please don't push me to update. Thank you.

PORTNAME=	wget
PORTVERSION=	1.8.2
PORTREVISION=	5
CATEGORIES=	ftp www ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wget

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	sf
PATCHFILES=	wget_${PORTVERSION}-12.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sf@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP and FTP

.if !defined(WITHOUT_NLS)
LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old
.endif

CONFLICTS=	wget-devel-*

USE_REINPLACE=	yes
USE_PERL5_BUILD=	yes
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
