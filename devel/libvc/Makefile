# New ports collection makefile for:	libvc
# Date created:				12 May 2003
# Whom:	      				Oliver Braun
#
# $FreeBSD$
#

PORTNAME=	libvc
PORTVERSION=	003
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rolo

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A vCard library

USE_BZIP2=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		vc.3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for DOC in AUTHORS ChangeLog NEWS README THANKS doc/rfc2426.txt
	@${INSTALL_DATA} ${WRKSRC}/${DOC} ${DOCSDIR}
.endfor
.endif
	@${RM} -f ${PREFIX}/lib/libvc.la

.include <bsd.port.mk>
