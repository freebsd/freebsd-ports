# New ports collection makefile for:	varconf
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	varconf
PORTVERSION=	0.6.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A Configuration System for the STAGE Server

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20

USE_GCC=	3.4
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README COPYING AUTHORS THANKS NEWS
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
