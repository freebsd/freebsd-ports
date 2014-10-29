# Created by: ache
# $FreeBSD$

PORTNAME=	omi
PORTVERSION=	20030719
CATEGORIES=	ftp
MASTER_SITES=	http://www.secnetix.de/~olli/distfiles/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/
#	http://dorifer.heim3.tu-clausthal.de/~olli/omi/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"mirror" subtrees of FTP servers

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	freebsd

OPTIONS_DEFINE=	DOCS

pre-patch:
	${REINPLACE_CMD} -E -e "s@^(OPTFLAGS).*@\1=${CFLAGS}@" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omi ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README.txt README.html CHANGES BSD-COPYRIGHT
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
