# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	rpm2cpio
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert .rpm files for extraction with /usr/bin/cpio, needs just perl

NO_WRKSUBDIR=	yes

USES=		perl5
NO_BUILD=	yes
NO_ARCH=	yes
REINPLACE_ARGS=

PLIST_FILES=	bin/rpm2cpio.pl

do-extract:
	@${MKDIR} ${WRKSRC}
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|' ${FILESDIR}/${PORTNAME} >${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.pl

.include <bsd.port.mk>
