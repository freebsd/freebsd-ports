# New ports collection makefile for:	libungif
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libungif
PORTVERSION=	4.1.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools and library routines for working with GIF images

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
USE_BZIP2=	yes
USE_INC_LIBTOOL_VER=15

.ifdef (WITHOUT_X11)
PLIST_SUB+=	X11='@comment '
CONFIGURE_ARGS+=--with-x=no
PKGNAMESUFFIX=	-nox11
.else
USE_XLIB=	yes
PLIST_SUB+=	X11=''
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/UNCOMPRESSED_GIF ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
