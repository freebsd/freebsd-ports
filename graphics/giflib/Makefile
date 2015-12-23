# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	giflib
PORTVERSION=	5.1.1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Tools and library routines for working with GIF images

CONFLICTS=	libungif-[0-9]*

USES=		tar:bzip2 libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCBOOK DOCS
OPTIONS_SUB=	yes
DOCBOOK_DESC=	Generate API documentation (requires DOCS)
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCBOOK} && ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto \
		docbook-xml>0:${PORTSDIR}/textproc/docbook-xml
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCBOOK} || ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} \
		-e 's|SUBDIRS = lib util doc pic|SUBDIRS = lib util pic|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCBOOK} && ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
