# New ports collection makefile for:	varconf
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	varconf
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	ftp://victor.worldforge.org/%SUBDIR%/ \
		http://purple.worldforge.org/wf/downloads/libs/varconf/ \
		ftp://ftp.fr.gnome.org/%SUBDIR%/
MASTER_SITE_SUBDIR= pub/worldforge/libs/varconf

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A Configuration System for the STAGE Server

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

USE_LIBTOOL=	YES
USE_REINPLACE=	YES
GNU_CONFIGURE=	YES

post-patch:
	@${REINPLACE_CMD} -e 's|^doc_DATA = .*|#&|g' \
		-e 's|\(^pkgconfigdir =\) .*|\1 ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README COPYING AUTHORS THANKS NEWS
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
