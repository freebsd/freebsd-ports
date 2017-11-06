# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	blat
PORTVERSION=	36
CATEGORIES=	biology
MASTER_SITES=	http://hgwdev.cse.ucsc.edu/~kent/src/ \
		https://users.soe.ucsc.edu/~kent/src/
DISTNAME=	${PORTNAME}Src${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast tool for local sequence similarity searches

LICENSE=	NONE

LIB_DEPENDS=	libpng.so:graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}Src

USES=		gmake mysql ssl zip
MAKEFILE=	makefile
MAKE_ENV=	MACHTYPE="${ARCH}" STRIP="${TRUE}"
MAKE_ARGS=	HOME="${WRKSRC}/${BINDIR}"

CFLAGS+=	-I${OPENSSLINC}
CPPFLAGS+=	-I${OPENSSLINC} $$(libpng-config --cflags)
LDFLAGS+=	-L${OPENSSLLIB} $$(libpng-config --ldflags) \
		-L${LOCALBASE}/lib/mysql

SUB_FILES=	pkg-message

PLIST_FILES=	${EXECUTABLES:S,^,bin/,} \
		lib/blat/webBlat/webBlat \
		lib/blat/webBlat/install.txt

EXECUTABLES=	blat faToNib faToTwoBit gfClient gfServer nibFrag \
		pslPretty pslReps pslSort twoBitInfo twoBitToFa

OPTIONS_DEFINE=	DOCS

post-patch:
	@${MKDIR} ${WRKSRC}/bin/${ARCH}
	@${MKDIR} ${WRKSRC}/lib/${ARCH}
	@${FIND} ${WRKSRC} -name "makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$${DESTDIR}||g'
	@${REINPLACE_CMD} -e \
		's|cd |$$(MAKE) -C | ; \
		 s| &&.*||' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 s|^COPT=.*|COPT=$${CPPFLAGS}| ; \
		 s|^L=.*|L=$${LDFLAGS}|' ${WRKSRC}/inc/common.mk

do-install:
.for exe in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${ARCH}/${exe} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/blat/webBlat
	${INSTALL_PROGRAM} ${WRKSRC}/webBlat/webBlat ${STAGEDIR}${PREFIX}/lib/blat/webBlat
	${INSTALL_DATA} ${WRKSRC}/webBlat/install.txt ${STAGEDIR}${PREFIX}/lib/blat/webBlat

.include <bsd.port.mk>
