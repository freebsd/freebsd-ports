# New ports collection makefile for:	varconf
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	varconf
PORTVERSION=	0.6.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.worldforge.org/libs/varconf/ \
		http://purple.worldforge.org/wf/downloads/libs/varconf/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A Configuration System for the STAGE Server

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

USE_LIBTOOL_VER=	15
USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g ; \
		s|\(^pkgconfigdir =\) .*|\1 ${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README COPYING AUTHORS THANKS NEWS
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
