# New ports collection makefile for:   kvirc
# Date created:        05 January 2004
# Whom:                Michael Ranner
#
# $FreeBSD$
#

PORTNAME=	kvirc
PORTVERSION=	3.0.1
CATEGORIES=	irc kde
MASTER_SITES=	ftp://ftp.kvirc.net/pub/%SUBDIR%/ \
		ftp://ftp.de.kvirc.net/%SUBDIR%/ \
		ftp://ftp.kvirc.de/pub/%SUBDIR%/ \
		ftp://kvirc.firenze.linux.it/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}/source/

MAINTAINER=	mranner@inode.at
COMMENT=	IRC client for QT and KDE

LIB_DEPENDS=	gsm.1:${PORTSDIR}/audio/gsm

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=		yes
USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	15
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man/man1
PLIST_SUB=		VER=${PORTVERSION}

MAN1=	kvirc.1

post-patch:
	${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.include <bsd.port.mk>
