# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dia2code+
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF/dia2code/dia2code+/${PORTVERSION}
DISTNAME=	dia2code-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Complete rewrite of dia2code in C++

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf:build compiler:c++11-lib gnome iconv
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/dia2code \
		man/man1/dia2code.1.gz

post-patch:
	@${REINPLACE_CMD} '/dia2code_CXXFLAGS =/ s,-fprofile-arcs,,' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/dia2code.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
