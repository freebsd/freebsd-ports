# New ports collection makefile for:    xmame
# Date created:         4 Sep 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmame
PORTVERSION=	0.37b7.1
PORTREVISION=	0
CATEGORIES=	emulators
MASTER_SITES=	http://x.mame.net/download/ \
		ftp://ftp.kaupp.cx/pub/xmame/ \
		http://www.ozemail.com.au/~knebauer/xmame/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	c9710216@studentmail.newcastle.edu.au

USE_XPM=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.unix

MAN6=		xmame.6

XMAMEDOCS=	changes.mame changes.unix gamelist.mame \
		imgtool.txt liesmich.unix multiplayer-readme.txt \
		readme.mame todo xmame-doc-1.html xmame-doc-2.html \
		xmame-doc-3.html xmame-doc-4.html xmame-doc-5.html \
		xmame-doc-6.html xmame-doc-7.html xmame-doc.html \
		xmame-doc.lyx xmame-doc.ps xmame-doc.sgml xmame-doc.txt

.if !defined(NOPORTDOCS)
PLIST_SUB+=	PORTDOCS=""
.else
PLIST_SUB+=	PORTDOCS="@comment "
.endif

# the large number of sed regexes here is intended to make this port a whole
# lot easier to maintain - please don't convert them into a patch.
post-patch:
	${PERL} -pi -e "s@%%PREFIX%%@${PREFIX}@g" ${WRKSRC}/doc/xmamerc.dist
	@${CP} ${WRKSRC}/makefile.unix ${WRKSRC}/makefile.unix.sed
	${SED} -e "s@= gcc@?=  ${CC}@g" -e "s@= -O -Wall@?=  ${CFLAGS}@g" \
		-e "s@= cp@?=  ${INSTALL} ${COPY}@g" -e "s@/usr/games@${PREFIX}/bin@g" \
		-e "s@/usr/local/man/man6@${PREFIX}/man/man6@g" \
		-e "s@/usr/games/lib/\$\(NAME\)@${PREFIX}/share/\$\(NAME\)@g" \
		-e "s@/usr/X11R6@${X11BASE}@g" -e "s@ARCH  = linux@ARCH  = freebsd@g" \
			${WRKSRC}/makefile.unix.sed > ${WRKSRC}/makefile.unix

post-install:
	${MV} ${PREFIX}/bin/xmame.x11 ${PREFIX}/bin/xmame
	${MKDIR} ${PREFIX}/share/xmame ${PREFIX}/share/xmame/hi ${PREFIX}/share/xmame/roms
	${CHMOD} 777 ${PREFIX}/share/xmame/hi
	${INSTALL_DATA} ${WRKSRC}/doc/xmamerc.dist ${PREFIX}/share/xmame/xmamerc
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xmame
.for file in ${XMAMEDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/xmame
.endfor
.endif
	
.include <bsd.port.mk>
