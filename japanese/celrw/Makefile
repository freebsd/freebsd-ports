PORTNAME=	celrw
PORTVERSION=	0.16
CATEGORIES=	japanese
MASTER_SITES=	http://www.nurs.or.jp/~kurati/celrw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cellular phone-number read/write tool (in Japan only)
WWW=		http://www.nurs.or.jp/~kurati/celrw/

USES=	tar:bzip2
GNU_CONFIGURE=	yes
MAKE_ARGS=	VERSION="${PORTVERSION}" OPTFLAGS="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/celrw

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-extract:
.for file in config.guess config.sub install.sh
	@${RM} ${WRKSRC}/${file}
	@${TOUCH} ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/celrw ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
