# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=		kbear
PORTVERSION=		3.0.a.1
PORTREVISION=	12
CATEGORIES=		ftp kde
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/3.0alpha1
DISTNAME=		${PORTNAME}-${PORTVERSION:S/.a.1/alpha1b/}-1.src

PATCH_SITES=		http://www.brueffer.de/distfiles/
PATCHFILES=		${DISTNAME:S/.src/-patch/}.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical FTP client for KDE

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.a.1/alpha1b/}

USE_LDCONFIG=	yes
USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	XML2POT=${TRUE} PO2XML=${TRUE}
LDFLAGS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|-fPIC|g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
