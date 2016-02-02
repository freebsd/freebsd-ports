# Created by: ache
# $FreeBSD$

PORTNAME=	omi
PORTVERSION=	20030719
CATEGORIES=	ftp
MASTER_SITES=	http://www.secnetix.de/~olli/distfiles/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/
#		http://dorifer.heim3.tu-clausthal.de/~olli/omi/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"mirror" subtrees of FTP servers

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-COPYRIGHT

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	freebsd

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.txt README.html CHANGES

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${REINPLACE_CMD} -E -e "s@^(OPTFLAGS).*@\1=${CFLAGS}@" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omi ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
