# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	biorythm
PORTVERSION=	1.1.4
CATEGORIES=	games
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple biorhythm calculation program

LIB_DEPENDS=	libshhmsg.so:${PORTSDIR}/devel/libshhmsg \
		libshhopt.so:${PORTSDIR}/devel/libshhopt

PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/${PORTNAME} man/man6/${PORTNAME}.6.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/VERSION/s|[[:space:]]"$$|\\n"| ; \
		/COMPILED_DATE/d' ${WRKSRC}/biorythm.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I. -I${LOCALBASE}/include \
		-DVERSION=\"${PORTVERSION}\" -D_ANSI_SOURCE *.c \
		-o ${PORTNAME} -L${LOCALBASE}/lib -lshhmsg -lshhopt -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
