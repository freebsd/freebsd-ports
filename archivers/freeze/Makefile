# Created by: lukin@okbmei.msk.su
# $FreeBSD$

PORTNAME=	freeze
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://web.warwick.ac.uk/ftp/pub/compression/ \
		http://www.rebootking.de/distfiles/ \
		http://ngsoftwareltd.com/freebsd/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compression program - often used in QNX

LICENSE=	NONE

DEPRECATED=	unknown license
EXPIRATION_DATE=	2018-08-15

CONFLICTS_INSTALL=	mlt-[0-9]*
GNU_CONFIGURE=	yes
ALL_TARGET=	prog

MAKE_ARGS+=	CFLAGS="${CFLAGS} -I. -DCOMPAT" CC="${CC}"

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
