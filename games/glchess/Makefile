# New ports collection makefile for:	glchess
# Date created:				Wed Jul 18 08:35:56 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	glchess
PORTVERSION=	0.4.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
USE_AUTOMAKE_VER=	14

MAN6=		${PORTNAME}.6

pre-patch:
	@${PERL} -pi.orig -e 's!/usr/local/share/games/glchess!${DATADIR}!' \
		${WRKSRC}/glchessrc
	@${PERL} -pi.orig -e 's!/etc!${PREFIX}/etc!' \
		${WRKSRC}/src/config.c
	@${PERL} -pi.orig -e 's|^aclocal|${ACLOCAL}|; \
		s|^autoconf|${AUTOCONF}|; s|^automake|${AUTOMAKE}|' \
		${WRKSRC}/autogen.sh

pre-configure:
	cd ${WRKSRC}; ${SH} autogen.sh

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/textures
	@${INSTALL_PROGRAM} ${WRKSRC}/src/glchess \
		${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/glchessrc \
		${PREFIX}/etc
	@${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.6 \
		${PREFIX}/man/man6
	@${INSTALL_DATA} ${WRKSRC}/textures/*.rgb \
		${DATADIR}/textures
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
