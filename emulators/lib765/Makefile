# New ports collection makefile for:	lib765
# Date created:			2003-10-27
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	lib765
PORTVERSION=	0.4.1
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.seasip.demon.co.uk/Unix/LibDsk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulation of uPD765a Floppy Disc Controller

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog doc/765.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
