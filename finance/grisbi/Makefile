# New ports collection makefile for:	grisbi
# Date created:		19 November 2002
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	grisbi
PORTVERSION=	0.4.5
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A personnal accounting application

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12 libcapplet libxml gnomepanel orbit gdkpixbuf gnomelibs gnomeprint
USE_BISON=	yes
USE_BZIP2=	yes
USE_AUTOCONF_VER=	213

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"		\
		AUTOHEADER="${AUTOHEADER}" AUTOCONF="${AUTOCONF}"

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:"
	@${ECHO_MSG}

.include <bsd.port.mk>
