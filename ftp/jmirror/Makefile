# New ports collection makefile for:	jmirror
# Date Created:		4 Febuary 1999
# Whom:			Justin Robinson
#
# $FreeBSD$
#

PORTNAME=	jmirror
PORTVERSION=	1.0b
CATEGORIES=	ftp
MASTER_SITES=	http://keyserver.kjsl.com/~jharris/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP mirroring program written in PERL (REQUIRES PERL5,Net::FTP)

RUN_DEPENDS=	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net

USE_PERL5=	YES
NO_BUILD=	YES
PLIST_FILES=	bin/jmirror %%EXAMPLESDIR%%/sample.jmirror.conf
PLIST_DIRS=	%%EXAMPLESDIR%%

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jmirror ${PREFIX}/bin/jmirror
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.jmirror.conf ${EXAMPLESDIR}/sample.jmirror.conf

.include <bsd.port.mk>
