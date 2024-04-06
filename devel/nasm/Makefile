PORTNAME=	nasm
PORTVERSION=	2.16.02
PORTEPOCH=	2
CATEGORIES=	devel lang
MASTER_SITES=	https://www.nasm.us/pub/nasm/releasebuilds/${PORTVERSION}/ \
		https://mirror.sobukus.de/files/src/nasm/

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	General-purpose multi-platform x86 and amd64 assembler
WWW=		https://www.nasm.us/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 cpe gmake perl5 tar:xz
CPE_VENDOR=	nasm
CPE_PRODUCT=	netwide_assembler
USE_PERL5=	build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_func_strspn=yes

MAKE_ARGS+=	INSTALLROOT=${STAGEDIR}

PLIST_FILES=	bin/nasm \
		bin/ndisasm \
		share/man/man1/nasm.1.gz \
		share/man/man1/ndisasm.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-xdoc${EXTRACT_SUFX}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/nasmdoc.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
