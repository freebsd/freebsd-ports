# Ports collection makefile for:  wget
# Date created:			  31 December 1996
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wget
PORTVERSION=	1.8.2
PORTREVISION=	3
CATEGORIES=	ftp www ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wget

PATCH_SITES=	${MASTER_SITE_DEBIAN_POOL}
PATCHFILES=	wget_${PORTVERSION}-10.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sf@FreeBSD.org
COMMENT=	Retrieve files from the Net via HTTP and FTP

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_REINPLACE=	yes
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS=	--with-ssl=no
.else
USE_OPENSSL=	yes
.endif
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

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
