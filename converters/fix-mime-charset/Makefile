# Created by: Nosov Artem <chip-set@mail.ru>
# $FreeBSD$

PORTNAME=	fix-mime-charset
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	converters textproc russian ukrainian
MASTER_SITES=	SF/fix-mime-chr/${PORTNAME}/${PORTVERSION}

MAINTAINER=	chip-set@mail.ru
COMMENT=	Fix incorrect Content-Type MIME headers of e-mail messages

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libenca.so:${PORTSDIR}/converters/enca

PORTDOCS=	README.koi8r README

GNU_CONFIGURE=	yes
USES=		perl5
USE_PERL5=	build

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/fix-mime-charset \
		man/man1/fix-mime-charset.1.gz

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
