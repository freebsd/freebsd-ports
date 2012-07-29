# New ports collection makefile for:	excido
# Date created:				19 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	excido
PORTVERSION=	0.1.5c
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://offload2.icculus.org:9090/excido/ \
		http://offload1.icculus.org:9090/excido/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable fast-paced 3D shooter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	physfs.1:${PORTSDIR}/devel/physfs

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	image sdl ttf
USE_OPENAL=	al alut
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
