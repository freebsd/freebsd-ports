PORTNAME=	aewan
PORTVERSION=	1.0.01
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Curses-based program for the creation and editing of ASCII art
WWW=		http://aewan.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/aecat bin/aewan bin/aemakeflic \
		man/man1/aecat.1.gz \
		man/man1/aewan.1.gz \
		man/man1/aemakeflic.1.gz \
		man/man5/aewan.5.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|OSTYPE == |OSTYPE = |g' ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
