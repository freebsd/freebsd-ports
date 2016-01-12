# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	hnb
PORTVERSION=	1.9.17
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hierarchical NoteBook a data organizer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

ONLY_FOR_ARCHS=	i386

USES=		gmake
ALL_TARGET=	# empty
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|; s|make|$${MAKE}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/libcli/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hnb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/../doc/hnb.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in Documentation.hnb Documentation.html hnbrc
	${INSTALL_DATA} ${WRKSRC}/../doc/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
