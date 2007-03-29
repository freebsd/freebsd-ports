# New ports collection makefile for: typespeed
# Date created:        06 September 2003
# Whom:                refugee
#
# $FreeBSD$
#

PORTNAME=	typespeed
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://tobias.eyedacor.org/typespeed/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Test your typing speed, and get your fingers\' CPS

USE_GETOPT_LONG=yes

SCOREPREFIX?=	/var/games
SCOREDIR=	${SCOREPREFIX}/typespeed
SCORECAT=	dos dut eng fin fra ger ita portuguese prog spanish thai unix

SOURCES=	file.c menu.c misc.c network.c typespeed.c

LDFLAGS+=	-L${LOCALBASE}/lib -lncurses
CFLAGS+=	-I${LOCALBASE}/include -D_GNU_SOURCE -DWORDDIR=\"${DATADIR}\" \
		-DHIGHDIR=\"${SCOREDIR}\" -DHIGHDIR=\"${SCOREDIR}\"

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	SCOREDIR="${SCOREDIR}" SCORECAT="${SCORECAT}"
MAN1=		typespeed.1

post-patch:
	@${REINPLACE_CMD} -e 's|\(/etc\)|${PREFIX}\1|' \
		${WRKSRC}/pathnames.h

post-extract:
	@${ECHO} ${DATADIR} > ${WRKSRC}/typespeedrc

do-build:
# build highscore converter
	${CC} ${CFLAGS} ${WRKSRC}/convert.c -o ${WRKSRC}/convert

# build typespeed
.for f in ${SOURCES}
	${CC} ${CFLAGS} -c ${WRKSRC}/${f} -o ${WRKSRC}/${f:C/\.c/.o/}
.endfor
	${CC} ${LDFLAGS} ${SOURCES:C/(.*)\.c/${WRKSRC}\/\1.o/} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} -g games -m 2555 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/convert ${PREFIX}/bin/${PORTNAME}-hs-conv
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${MANPREFIX}/man/man1/${MAN1}
	${INSTALL_DATA} ${WRKSRC}/typespeedrc ${PREFIX}/etc/typespeedrc.dist
.if !exists(${PREFIX}/etc/typespeedrc)
	${INSTALL_DATA} ${WRKSRC}/typespeedrc ${PREFIX}/etc
.endif
	${MKDIR} ${DATADIR}
	${FIND} ${WRKSRC} -name "words.*" -type f \
		-exec ${INSTALL_DATA} {} ${DATADIR} \;

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
