# Ports collection makefile for:  wget
# Date created:			  31 December 1996
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wget
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	ftp www ipv6
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.dl.ac.uk/ccp14/ftp-mirror/wget/pub/unix/util/wget/ \
		ftp://ftp.informatik.hu-berlin.de/gnu/wget/ \
		ftp://ftp.uni-mainz.de/pub/gnu/wget/ \
		ftp://ftp.max.irk.ru/unix/net/www/wget/
MASTER_SITE_SUBDIR=	wget

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/kame/misc/&,}
PATCHFILES=	wget-17-v6-20010716a.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sf@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}
.endif
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

MAN1=		wget.1

# made by broken KAME patch. Already contacted.
post-patch:
	@${RM} -f ${WRKSRC}/po/zh.po*

pre-build:
	@${RM} -f ${WRKSRC}/doc/wget.info*

post-install:
	install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
