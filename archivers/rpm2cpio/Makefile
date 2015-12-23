# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	rpm2cpio
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Convert .rpm files to cpio format

NO_WRKSUBDIR=	yes

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/rpm2cpio.pl

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/${PORTNAME} ${WRKSRC}/${PORTNAME}

do-install:
# Installed as rpm2cpio.pl to not break existing scripts
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.pl

.include <bsd.port.mk>
