# New ports collection makefile for:	gnomermind
# Date created:				11 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomermind
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A puzzle game for Gnome, loosely based on the classic MasterMind game

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gdkpixbuf gnomehack gnomelibs gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	OLD_PO_FILE_INPUT=1

post-patch:
	@${REINPLACE_CMD} -e 's|^Info|#Info|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog HACKING NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
