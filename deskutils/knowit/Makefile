# New ports collection makefile for:	knowit
# Date created:			2002/12/08
# Whom:				Alan Eldridge <ports@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	knowit
PORTVERSION=	0.10
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A note manager with tree organization that uses RTF for storage

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
INSTALLS_ICONS=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

DOCSDIR=	${PREFIX}/share/doc/HTML

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
