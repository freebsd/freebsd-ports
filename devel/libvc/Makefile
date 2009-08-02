# New ports collection makefile for:	libvc
# Date created:				12 May 2003
# Whom:	      				Oliver Braun
#
# $FreeBSD$
#

PORTNAME=	libvc
PORTVERSION=	003
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rolo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A vCard library

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_BISON=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

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
