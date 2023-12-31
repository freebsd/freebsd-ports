PORTNAME=	slump
PORTVERSION=	0.003.02
CATEGORIES=	games
MASTER_SITES=	http://www.samiam.org/slump/old/slump/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fork of SLIGE that is optimized for making FreeDoom maps
WWW=		https://www.samiam.org/slump.html

LICENSE=	GPLv2+

USES=	tar:bzip2

MAKE_ARGS=	FLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1302505
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
