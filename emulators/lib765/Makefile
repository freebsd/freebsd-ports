# New ports collection makefile for:	lib765
# Date created:			2003-10-27
# Whom:				Alexey V. Antipovsky <kemm@in-line.ru>
#
# $FreeBSD$
#

PORTNAME=	lib765
PORTVERSION=	0.3.4
CATEGORIES=	emulators devel
MASTER_SITES=	http://www.seasip.demon.co.uk/Unix/LibDsk/

MAINTAINER=	kemm@in-line.ru
COMMENT=	Emulation of uPD765a Floppy Disc Controller

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog doc/765.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
