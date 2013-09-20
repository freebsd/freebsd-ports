# Created by: Matthew Hunt <mph@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jzip
PORTVERSION=	2.0.1g
CATEGORIES=	games
MASTER_SITES=	LOCAL/mph
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-mode Infocom game interpreter

NO_WRKSUBDIR=	yes

USE_ZIP=	yes

CPPFLAGS+=	-DPOSIX -DHAVE_GETOPT

MAN1=		jzip.1
PORTDOCS=	Jzip.doc
PLIST_FILES=	bin/jzip

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC =|CC ?=| ; \
		 s|^CFLAGS =|CFLAGS +=| ; \
		 s|-DPOSIX|$${CPPFLAGS}| ; \
		 s|^LDFLAGS|#LDFLAGS| ; \
		 s|-lcurses|-ltermcap|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|^void main|int main|' ${WRKSRC}/jzexe.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} jzip ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} jzip.1 ${MANPREFIX}/man/man1)
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} Jzip.doc ${DOCSDIR})
.endif

.include <bsd.port.mk>
