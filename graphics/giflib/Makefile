# New ports collection makefile for:	libungif
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libungif
PORTVERSION=	4.1.0b1
CATEGORIES=	graphics
MASTER_SITES=	ftp://prtr-13.ucsc.edu/pub/libungif/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

USE_LIBTOOL=	yes

.ifdef (NO_X)
PLIST_SUB+=	X11='@comment '
CONFIGURE_ARGS+=--with-x=no
PKGNAMESUFFIX=	-nox11
.else
USE_XLIB=	yes
PLIST_SUB+=	X11=''
.endif

DOCDIR=		${PREFIX}/share/doc/libungif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UNCOMPRESSED_GIF ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCDIR}
.endif

.include <bsd.port.mk>
