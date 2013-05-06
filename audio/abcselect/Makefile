# Created by: Sue Blake <sue@FreeBSD.org>
# $FreeBSD$

PORTNAME=	abcselect
PORTVERSION=	1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.lautengesellschaft.de/cdmm/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract parts, movements, etc from abc music files

USES=		shebangfix
USE_PERL5_RUN=	yes
NO_BUILD=	yes

SHEBANG_FILES=	abcselect

MAN1=	abcselect.1
PLIST_FILES=	bin/abcselect

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcselect ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/abcselect.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
