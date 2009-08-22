# New ports collection makefile for:	rolo
# Date created:				04 April 2003
# Whom:	      				Andrew Hsu <ahsu@users.sf.net>
#
# $FreeBSD$
#

PORTNAME=	rolo
PORTVERSION=	011
CATEGORIES=	deskutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text-based contact management software

BUILD_DEPENDS=	${LOCALBASE}/lib/libvc.a:${PORTSDIR}/devel/libvc

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include \
		-L${PREFIX}/lib

MAN1=		rolo.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for DOC in AUTHORS ChangeLog NEWS README THANKS
	@${INSTALL_DATA} ${WRKSRC}/${DOC} ${DOCSDIR}
.endfor
.endif


.include <bsd.port.mk>
