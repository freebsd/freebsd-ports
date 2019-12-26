# Created by: Ganael Laplanche <ganael.laplanche@martymac.org>
# $FreeBSD$

PORTNAME=	par2cmdline-tbb
PORTVERSION=	20100203
PORTREVISION=	19
CATEGORIES=	archivers
MASTER_SITES=	http://chuchusoft.com/par2_tbb/
DISTNAME=	par2cmdline-0.4-tbb-${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Tools for using Parity v2 Archive files (tbb version)

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		amd64 i386

LIB_DEPENDS=	libtbb.so:devel/tbb

GNU_CONFIGURE=	yes
USES=		autoreconf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PORTDOCS=	README
CONFLICTS=	par2cmdline-[0-9]*

PLIST_FILES=	bin/par2 bin/par2create bin/par2repair bin/par2verify

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
