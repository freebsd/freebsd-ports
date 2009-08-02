# New ports collection makefile for:   libphish
# Date created:                17 Apr 2006
# Whom:                        Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=	libphish
PORTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/opdb/ \
		http://download2.berlios.de/opdb/ \

MAINTAINER=	citycat4@ngs.ru
COMMENT=	A cross-platform library to interact with the Open Phishing Database

BUILD_DEPENDS=	xmlwf:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	-I${LOCALBASE}/include -DFreeBSD
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} `${LS}` ${DOCSDIR}
.endif

.include <bsd.port.mk>
