# Created by: Rashid N. Achilov <shelton@granch.ru>
# $FreeBSD$

PORTNAME=	libphish
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.berlios.de/opdb/ \
		http://download2.berlios.de/opdb/ \

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform library to interact with the Open Phishing Database

BUILD_DEPENDS=	xmlwf:${PORTSDIR}/textproc/expat2

BROKEN=		No public distfiles

USES=		tar:bzip2 libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -DFreeBSD
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
