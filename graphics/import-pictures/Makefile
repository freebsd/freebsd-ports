# New ports collection makefile for:   import-pictures
# Date created:        7 May 2008
# Whom:                Alexander Kuehn
#
# $FreeBSD$
#

PORTNAME=	import-pictures
PORTVERSION=	1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.nagilum.org/unix/

MAINTAINER=	freebsd@nagilum.org
COMMENT=	Utility to copy/move pictures from a directory

RUN_DEPENDS=	p5-Image-ExifTool>=7.0:${PORTSDIR}/graphics/p5-Image-ExifTool \
		p5-TimeDate>=1.10:${PORTSDIR}/devel/p5-TimeDate \
		p5-Time-modules>=2006:${PORTSDIR}/devel/p5-Time-modules

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

MAN1=		import-pictures.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/import-pictures ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/import-pictures.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/import-pictures.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
