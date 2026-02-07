PORTNAME=	dia2code
PORTVERSION=	0.8.8
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Small utility used to generate code from a Dia diagram
WWW=		https://dia2code.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^0\.

USES=		gnome iconv
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	dia2code+

PLIST_FILES=	bin/dia2code \
		share/man/man1/dia2code.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/dia2code.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
