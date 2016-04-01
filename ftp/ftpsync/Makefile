# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ftpsync
PORTVERSION=	1.3.06
PORTEPOCH=	1
CATEGORIES=	ftp
MASTER_SITES=	http://download.clazzes.org/ftpsync/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0

MAINTAINER=	rodrigO@FreeBSD.org
COMMENT=	Synchronizes a local and a remote FTP directory trees

LICENSE=	GPLv2

RUN_DEPENDS=	p5-libwww>=5.805:www/p5-libwww

USES=		perl5 shebangfix tar:bzip2
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.pl
SHEBANG_FILES=	ftpsync.pl
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} Changes_1.00-1.3.04.txt License.txt \
	    ReadMe.txt ToDo.txt changelog  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
