# ex:ts=8
# Ports collection makefile for:	code-browser
# Date created:			Jan 25, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	code-browser
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Folding Text Editor

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_REINPLACE=	yes
USE_GNOME=	gtk20
USE_GCC=	3.4+

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not build on !i386; signal 11 errors during build"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," \
		-e "s,^CC,#CC," -e "s,^CFLAGS,#CFLAGS," \
		${WRKSRC}/${MAKEFILE} ${WRKSRC}/zinc/${MAKEFILE}

.include <bsd.port.post.mk>
