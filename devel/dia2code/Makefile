# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dia2code
PORTVERSION=	0.8.5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small utility used to generate code from a Dia diagram

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/dia2code \
		man/man1/dia2code.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/dia2code.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
