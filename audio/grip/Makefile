# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=	grip
PORTVERSION=	3.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=grip

MAINTAINER=	ports@geeksrus.net

LIB_DEPENDS=	id3-3.7.13:${PORTSDIR}/audio/id3lib \
		ghttp.1:${PORTSDIR}/www/libghttp

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_GNOMELIBS=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"

.if defined(WITH_DEBUG)
CONFIGURE_ENV+=	CFLAGS="-g" \
		LDFLAGS="-g -L${LOCALBASE}/lib"
.else
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
.endif

INSTALL_SUBDIRS=	contrib intl pixmaps po src
.if !defined(NOPORTDOCS)
INSTALL_SUBDIRS+=	doc
.endif

do-install:
	@cd ${WRKSRC}; ${MAKE} install-am
.for dir in ${INSTALL_SUBDIRS}
	@cd ${WRKSRC}/${dir}; ${MAKE} ${INSTALL_TARGET}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
