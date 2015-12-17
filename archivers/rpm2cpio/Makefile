# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	rpm2cpio
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Convert .rpm files for extraction with /usr/bin/cpio, needs just perl

NO_WRKSUBDIR=	yes

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/rpm2cpio.pl

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/${PORTNAME} ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.pl

.include <bsd.port.mk>
