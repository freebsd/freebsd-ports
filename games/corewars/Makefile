# $FreeBSD$

PORTNAME=	corewars
PORTVERSION=	0.9.13
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%2C%20tar.gz%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulation game where the goal is to crash each other's programs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libargp.a:devel/argp-standalone

USES=		gmake localbase
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
