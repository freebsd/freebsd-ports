PORTNAME=	fix-mime-charset
PORTVERSION=	0.5.3
PORTREVISION=	2
CATEGORIES=	converters textproc russian ukrainian
MASTER_SITES=	SF/fix-mime-chr/${PORTNAME}/${PORTVERSION}

MAINTAINER=	chip-set@mail.ru
COMMENT=	Fix incorrect Content-Type MIME headers of e-mail messages
WWW=		https://fix-mime-chr.sourceforge.net

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libenca.so:converters/enca

USES=		localbase perl5
USE_PERL5=	build

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/fix-mime-charset \
		man/man1/fix-mime-charset.1.gz
PORTDOCS=	README.koi8r README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
