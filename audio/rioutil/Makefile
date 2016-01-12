# Created by: George Reid <greid@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rioutil
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to interface with the Rio600, Rio800, and psa[play devices

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt*

.include <bsd.port.mk>
