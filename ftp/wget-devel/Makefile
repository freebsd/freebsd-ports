# Ports collection makefile for:  wget
# Date created:			  31 December 1996
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wget
PORTVERSION=	1.8.1
CATEGORIES=	ftp www
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.dl.ac.uk/ccp14/ftp-mirror/wget/pub/unix/util/wget/ \
		ftp://ftp.informatik.hu-berlin.de/gnu/wget/ \
		ftp://ftp.uni-mainz.de/pub/gnu/wget/ \
		ftp://ftp.max.irk.ru/unix/net/www/wget/ \
		http://www3.big.or.jp/~sian/linux/products/
MASTER_SITE_SUBDIR=	wget
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${EXTRA_PO}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sf@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}
.endif
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

MAN1=		wget.1

EXTRA_PO=	${PORTNAME}-${PORTVERSION}.ja.po.gz

post-extract:
	${RM} -f ${WRKSRC}/po/ja.po
	${GZIP_CMD} -dc ${DISTDIR}/${EXTRA_PO} > ${WRKSRC}/po/ja.po

post-patch:
	${RM} -f ${WRKSRC}/doc/wget.info*
# we don't need to run autoconf.
	${TOUCH} ${WRKSRC}/configure

post-install:
	install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
