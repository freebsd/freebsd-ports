PORTNAME=	dia2code+
PORTVERSION=	1.0.0
PORTREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	SF/dia2code/dia2code+/${PORTVERSION}
DISTNAME=	dia2code-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Complete rewrite of dia2code in C++
WWW=		https://dia2code.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Fails to build with libxml2 2.13.0 (PR 279759)
EXPIRATION_DATE=2024-07-16

USES=		autoreconf:build compiler:c++11-lib gnome iconv
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	dia2code

PLIST_FILES=	bin/dia2code \
		share/man/man1/dia2code.1.gz

post-patch:
	@${REINPLACE_CMD} '/dia2code_CXXFLAGS =/ s,-fprofile-arcs,,' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/dia2code.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
