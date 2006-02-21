# New ports collection makefile for:	libytnef
# Date created:		21 Feb 2005
# Whom:			Rodrigo Graeff <delphus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libytnef
PORTVERSION=	1.5
CATEGORIES=	converters mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ytnef

MAINTAINER=	delphus@gmail.com
COMMENT=	Unpack data in MS Outlook TNEF format

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PORTDOCS=	AUTHORS NEWS README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
