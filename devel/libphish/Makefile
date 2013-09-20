# Created by: Rashid N. Achilov <shelton@granch.ru>
# $FreeBSD$

PORTNAME=	libphish
PORTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/opdb/ \
		http://download2.berlios.de/opdb/ \

MAINTAINER=	citycat4@ngs.ru
COMMENT=	A cross-platform library to interact with the Open Phishing Database

BUILD_DEPENDS=	xmlwf:${PORTSDIR}/textproc/expat2

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -DFreeBSD
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} `${LS}` ${DOCSDIR}
.endif

.include <bsd.port.mk>
