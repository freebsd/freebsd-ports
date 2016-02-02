# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	libburn
PORTVERSION=	1.4.2.pl01
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Libburnia library to read/write optical discs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
