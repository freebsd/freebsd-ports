# Created by: Rashid N. Achilov <shelton@granch.ru>
# $FreeBSD$

PORTNAME=	libphish
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/opdb/ \
		http://download2.berlios.de/opdb/ \

MAINTAINER=	citycat4@ngs.ru
COMMENT=	Cross-platform library to interact with the Open Phishing Database

BUILD_DEPENDS=	xmlwf:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	DOCS

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -DFreeBSD
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
