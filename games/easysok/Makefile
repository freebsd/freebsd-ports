# New ports collection makefile for:	easysok
# Date created:				15 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	easysok
PORTVERSION=	0.3.5
CATEGORIES=	games kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-kde3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sokoban game for KDE3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e \
		's|-lkdeprint|$$(LIB_KDEPRINT) $$(LIBPTHREAD)|g' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
