# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dia2code
PORTVERSION=	0.8.8
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Small utility used to generate code from a Dia diagram

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^0\.

USES=		gnome iconv
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/dia2code \
		man/man1/dia2code.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/dia2code.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
