# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ftpsync
PORTVERSION=	1.3.03
PORTEPOCH=	1
CATEGORIES=	ftp
MASTER_SITES=	http://ftpsync.sourceforge.net/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Synchronizes a local and a remote FTP directory trees

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww

USES=		perl5 tar:bzip2 shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.pl
SHEBANG_FILES=	ftpsync.pl
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
