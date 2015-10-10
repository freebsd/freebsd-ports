# $FreeBSD$

PORTNAME=	vmw
PORTVERSION=	060510
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://sites.google.com/site/chitchatvmback/storage/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	VM Back Command Line Tools for VMware

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}/src
USES=		iconv
MAKE_ENV+=	__MAKE_CONF=/dev/null ASFLAGS="${ASFLAGS}"
MAKE_ENV+=	LD="${CC}"

SBINS=		vmw vmshrink vmftp

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README-eucj.TXT README-sjis.TXT README.TXT
.for i in ${SBINS}
PORTDOCS+=	${i}-eucj.txt ${i}-sjis.txt ${i}.txt
.endfor
.for i in ${SBINS}
PLIST_FILES+=	sbin/${i}
.endfor

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
.if !exists(/usr/lib32/libc.so)
IGNORE=		please install lib32
.endif
.if !empty(ICONV_LIB)
IGNORE=		needs 32bit libiconv
.endif
CFLAGS+=	-m32
ASFLAGS+=	--32
LDFLAGS+=	-m32 -B/usr/lib32 -L/usr/lib32
LD=	${CC}
.endif

.if empty(ICONV_LIB)
FTPLIB=
MAKE_ENV+=	FTPLIB="${FTPLIB}"
.else
CFLAGS+=	-I${LOCALBASE}/include
.endif

do-install:
.for i in ${SBINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/sbin/
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/.. && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.post.mk>
