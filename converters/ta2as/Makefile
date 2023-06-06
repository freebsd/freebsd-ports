PORTNAME=	ta2as
PORTVERSION=	0.8.2
CATEGORIES=	converters devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	TASM to AT&T asm syntax converter (GNU AS)
WWW=		https://github.com/mefistotelis/ta2as

LICENSE=	TA2AS
LICENSE_NAME=	TA2AS license
LICENSE_FILE=	${WRKSRC}/legal.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	mefistotelis

WRKSRC_SUBDIR=	ta2as

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-extract:
	@${CP} -f ${FILESDIR}/strtolower.c ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e \
		's|strlwr|strtolower|' ${WRKSRC}/${PORTNAME}.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} main.c strtolower.c ${PORTNAME}.c \
		-o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
