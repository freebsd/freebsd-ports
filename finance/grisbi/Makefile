# New ports collection makefile for:	grisbi
# Date created:		19 November 2002
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	grisbi
PORTVERSION=	0.4.3
CATEGORIES=	finance
MASTER_SITES=	http://grisbi.org/download/packages/${PORTVERSION}/sources/		\
		http://cedricauger.free.fr/download/packages/${PORTVERSION}/sources/	\
		http://grisbi.gegeweb.net/download/packages/${PORTVERSION}/sources/

MAINTAINER=	thierry@pompo.net
COMMENT=	A personnal accounting application

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old	\
		iconv.3:${PORTSDIR}/converters/libiconv

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12 libcapplet libxml gnomepanel orbit gdkpixbuf gnomelibs gnomeprint
USE_BISON=	yes
USE_BZIP2=	yes
USE_AUTOCONF=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"		\
		AUTOHEADER="${AUTOHEADER}" AUTOCONF="${AUTOCONF}"

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:"
	@${ECHO_MSG}

.include <bsd.port.mk>
