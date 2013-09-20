# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	esecanna-module-wnn6
PORTVERSION=	1.0.0
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Esecanna module for Wnn6

LIB_DEPENDS=	wnn6.2:${PORTSDIR}/japanese/Wnn6-lib
RUN_DEPENDS=	${LOCALBASE}/sbin/esecannaserver:${PORTSDIR}/japanese/esecanna

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
LDFLAGS+=	-L${PREFIX}/lib
CFLAGS+=	-I${PREFIX}/include/wnn6

DIST_SUBDIR=    esecanna

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
.for i in README CHANGES
	${INSTALL_DATA} ${WRKSRC}/${i}.jp ${PREFIX}/share/doc/esecanna/${i}.wnn6.jp
.endfor
.endif

.include <bsd.port.mk>
