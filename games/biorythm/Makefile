# New ports collection makefile for:	biorythm
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	biorythm
PORTVERSION=	1.1.4
CATEGORIES=	games
MASTER_SITES=	http://shh.thathost.com/pub-unix/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple biorhythm calculation program

LIB_DEPENDS=	shhmsg.1:${PORTSDIR}/devel/libshhmsg \
		shhopt.1:${PORTSDIR}/devel/libshhopt

MAN6=		${PORTNAME}.6
PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/VERSION/s|[[:space:]]"$$|\\n"| ; \
		/COMPILED_DATE/d' ${WRKSRC}/biorythm.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I. -I${LOCALBASE}/include \
		-DVERSION=\"${PORTVERSION}\" -D_ANSI_SOURCE *.c \
		-o ${PORTNAME} -L${LOCALBASE}/lib -lshhmsg -lshhopt -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${MAN6PREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
