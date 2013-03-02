# Created by: Jamie Hermans <jamie@hermans.ca>
# $FreeBSD$

PORTNAME=	jhead
PORTVERSION=	2.97
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Exif Jpeg camera setting parser, rotator, and much more

RUN_DEPENDS=	jpegtran:${PORTSDIR}/graphics/jpeg

MAKEFILE=	makefile
MAKE_JOBS_SAFE=	yes

MAN1=		jhead.1
PORTDOCS=	usage.html
PLIST_FILES=	bin/jhead

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS|#CFLAGS|' ${WRKSRC}/makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} jhead ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} jhead.1 ${MANPREFIX}/man/man1)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} usage.html ${DOCSDIR})
.endif

.include <bsd.port.mk>
