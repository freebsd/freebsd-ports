# ex:ts=8
#
# New ports collection makefile for:	knowit
# Date created:			2002/12/08
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	knowit
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://knowit.sourceforge.net/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A note manager with tree organization that uses RTF for storage

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
