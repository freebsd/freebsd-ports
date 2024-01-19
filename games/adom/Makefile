PORTNAME=	adom
PORTVERSION=	3.0.6
CATEGORIES=	games
MASTER_SITES=	http://www.adom.de/home/download/old/${PORTVERSION}/
DISTNAME=	${PORTNAME}_freebsd_${ARCH_BITS}_${PORTVERSION}

MAINTAINER=	arcade@b1t.name
COMMENT=	Rogue-like advanced rpg with color support (binary port)
WWW=		https://www.adom.de

LICENSE=	UNKNOWN
LICENSE_NAME=	The ADOM License
LICENSE_FILE=	${WRKSRC}/docs/readme1st.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror

LIB_DEPENDS+=	libncursesw.so.8:misc/compat12x

NO_CDROM=	Copy of CD must be sent to author

ONLY_FOR_ARCHS=	amd64 i386

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/adom

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
ARCH_BITS=	64
.elif ${ARCH} == i386
ARCH_BITS=	32
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adom ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in adomfaq.txt manual.txt credits.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
