# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=	validns
PORTVERSION=	0.7
CATEGORIES=	dns security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	umq@ueo.co.jp
COMMENT=	A high performance DNS/DNSSEC zone validator

LICENSE=	BSD

LIB_DEPENDS=	Judy:${PORTSDIR}/devel/judy

ALL_TARGET=

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
OPTIONS_DEFINE=	DOCS
PORTDOCS=	Changes README installation.mdwn notes.mdwn \
		technical-notes.mdwn todo.mdwn usage.mdwn

NO_STAGE=	yes
.include <bsd.port.pre.mk>
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${MAN1:S,^,${WRKSRC}/,} ${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
