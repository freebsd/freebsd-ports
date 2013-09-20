# Created by: Christian Brueffer <chris@unixpages.org>
# $FreeBSD$

PORTNAME=	mencal
PORTVERSION=	2.4
CATEGORIES=	deskutils
MASTER_SITES=	http://kyberdigi.cz/projects/mencal/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A variation of the unix command cal

LICENSE=	GPLv2

NO_BUILD=	yes

USES=		perl5
USE_PERL5=	run

PLIST_FILES=	bin/mencal

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/^#!/s|/.*|${PERL} -w|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mencal ${PREFIX}/bin

.include <bsd.port.mk>
